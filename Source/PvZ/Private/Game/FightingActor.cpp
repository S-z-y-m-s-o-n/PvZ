
#include "Game/FightingActor.h"

#include "PaperFlipbookComponent.h"
#include "Components/BoxComponent.h"

AFightingActor::AFightingActor()
{
	SpriteComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	SetRootComponent(SpriteComponent);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetupAttachment(SpriteComponent);
}

void AFightingActor::BeginPlay()
{
	AActor::BeginPlay();

	Health = MaxHealth;
}

float AFightingActor::Damage(float value, EDamageType damageType, AActor* source)
{
	if (value == -1)
	{
		Destroy();
	}
	Health -= value;
	if (Health == 0)
	{
		Destroy();
	}
	if (Health < 0)
	{
		Destroy();
		return abs(Health);
	}
	return 0;
}