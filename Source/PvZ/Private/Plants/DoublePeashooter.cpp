
#include "Plants/DoublePeashooter.h"

#include "Kismet/GameplayStatics.h"

#include "Game/GridCell.h"

#include "Projectiles/PeaProjectile.h"

void ADoublePeashooter::Plant(AGridCell* cell)
{
	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, this, &ADoublePeashooter::PrepareShoot, 1, false);

	Super::Plant(cell);
}

void ADoublePeashooter::Tick(float DeltaTime)
{
	if (bReadyToShoot)
	{
		TArray<AActor*> fightingActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFightingActor::StaticClass(), fightingActors);
		TArray<AFightingActor*> actorsToAttack;
		for (int i = 0; i < fightingActors.Num() - 1; i++)
		{
			AFightingActor* actor = Cast<AFightingActor>(fightingActors[i]);
			if (actor->Side == ESide::Zombies && actor->bIsDamagable && actor->Row == OccupiedGridCell->GridPosition.X && actor->GetActorLocation().X > GetActorLocation().X)
			{
				Shoot(true);
			}
		}
	}

	APlant::Tick(DeltaTime);
}

void ADoublePeashooter::Shoot(bool bContinue)
{
	AActor* projectile = GetWorld()->SpawnActor(ProjectileClass.Get());
	projectile->SetActorLocation(GetActorLocation());
	((AProjectile*)projectile)->Owner = this;
	bReadyToShoot = false;
	if (bContinue)
	{
		FTimerHandle handle;
		GetWorldTimerManager().SetTimer(handle, this, &ADoublePeashooter::ShootF, 0.1, false);
	}
	else
	{
		FTimerHandle handle;
		GetWorldTimerManager().SetTimer(handle, this, &ADoublePeashooter::PrepareShoot, 0.95, false);
	}
}

