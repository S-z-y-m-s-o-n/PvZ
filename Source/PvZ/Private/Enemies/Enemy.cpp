
#include "Enemies/Enemy.h"

#include "PaperFlipbookComponent.h"

AEnemy::AEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	Sprite = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	SetRootComponent(Sprite);

	Sprite->SetCollisionResponseToChannel(ECC_GameTraceChannel3, ECollisionResponse::ECR_Block);
}

void AEnemy::BeginPlay()
{
	AActor::BeginPlay();
	
}

void AEnemy::Tick(float DeltaTime)
{
	AActor::Tick(DeltaTime);

}

void AEnemy::Damage(float value)
{
	Health -= value;
	if (Health <= 0)
	{
		Destroy();
	}
}