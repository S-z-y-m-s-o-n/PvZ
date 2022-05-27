
#include "Enemies/StandardZombie.h"


AStandardZombie::AStandardZombie()
{
	PrimaryActorTick.bCanEverTick = true;

	Side = ESide::Zombies;
}

void AStandardZombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector Location = GetActorLocation();
	SetActorLocation(FVector(Location.X - DeltaTime * speed, Location.Y, Location.Z));
}