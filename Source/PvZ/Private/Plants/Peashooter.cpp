
#include "Plants/Peashooter.h"

APeashooter::APeashooter()
{

}

void APeashooter::Tick(float DeltaTime)
{
	APlant::Tick(DeltaTime);
	FHitResult Hit;
	FVector End = FVector(GetActorLocation().X, GetActorLocation().Y - 1500, GetActorLocation().Z);
	//GetWorld()->LineTraceSingleByChannel(Hit, GetActorLocation(), End, ECollisionChannel::)
}

void APeashooter::BeginPlay()
{
	Super::BeginPlay();
}