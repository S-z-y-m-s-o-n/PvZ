
#include "Projectiles/Projectile.h"

#include "Game/FightingActor.h"

#include "PaperFlipbookComponent.h"
#include "Components/BoxComponent.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	SpriteComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite Component"));
	SetRootComponent(SpriteComponent);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetupAttachment(SpriteComponent);
}

