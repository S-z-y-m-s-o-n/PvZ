
#include "Projectiles/PeaProjectile.h"

#include "PaperFlipbookComponent.h"

APeaProjectile::APeaProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	SpriteComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite Component"));
	SetRootComponent(SpriteComponent);
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

