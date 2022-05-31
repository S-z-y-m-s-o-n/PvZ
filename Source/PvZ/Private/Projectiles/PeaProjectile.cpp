
#include "Projectiles/PeaProjectile.h"

#include "PaperFlipbookComponent.h"

#include "Game/FightingActor.h"
#include "Game/Damage.h"

APeaProjectile::APeaProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	SpriteComponent->OnComponentBeginOverlap.AddDynamic(this, &APeaProjectile::OnSpriteBeginOverlap);
}

void APeaProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void APeaProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(DeltaTime * 425, 0, 0));
}

void APeaProjectile::OnSpriteBeginOverlap(UPrimitiveComponent* comp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AFightingActor* actor = Cast<AFightingActor>(OtherActor);
	if (actor && actor->Side == ESide::Zombies && actor->bIsDamagable)
	{
		actor->Damage(15, EDamageType::Other, Owner);
		Destroy();
	}
}


