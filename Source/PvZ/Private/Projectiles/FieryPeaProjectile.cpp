
#include "Projectiles/FieryPeaProjectile.h"

#include "PaperFlipbookComponent.h"

AFieryPeaProjectile::AFieryPeaProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	SpriteComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite Component"));
	SetRootComponent(SpriteComponent);
}

void AFieryPeaProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFieryPeaProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

