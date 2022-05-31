
#include "Plants/Peashooter.h"

#include "Kismet/GameplayStatics.h"

#include "Game/GridCell.h"

#include "Projectiles/PeaProjectile.h"

APeashooter::APeashooter()
{

}

void APeashooter::Plant(AGridCell* cell)
{
	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, this, &APeashooter::PrepareShoot, 1, false);

	Super::Plant(cell);
}

void APeashooter::Tick(float DeltaTime)
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
				AActor* projectile = GetWorld()->SpawnActor(ProjectileClass.Get());
				projectile->SetActorLocation(GetActorLocation() + FVector(0, 0.3, 0));
				bReadyToShoot = false;
				FTimerHandle handle;
				GetWorldTimerManager().SetTimer(handle, this, &APeashooter::PrepareShoot, 0.85, false);
			}
		}
	}

	APlant::Tick(DeltaTime);
}

void APeashooter::BeginPlay()
{
	Super::BeginPlay();
}