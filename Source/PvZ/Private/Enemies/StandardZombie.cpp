
#include "Enemies/StandardZombie.h"

#include "PaperFlipbookComponent.h"

#include "Enemies/Equipment/DamagableEquipment.h"
#include "Plants/Plant.h"

#include "Game/Damage.h"


AStandardZombie::AStandardZombie()
{
	PrimaryActorTick.bCanEverTick = true;

	Side = ESide::Zombies;

	bCanEatBrain = true;
}

void AStandardZombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetOverlappingActors(overlappingActors, APlant::StaticClass());
	for (int i = 0; i <= overlappingActors.Num() - 1; i++)
	{
		AFightingActor* actor = Cast<AFightingActor>(overlappingActors[i]);
		if (actor != nullptr)
		{
			if (actor->Side == ESide::Plants && actor->bIsDamagable)
			{
				actor->Damage(DeltaTime * 100, EDamageType::Eating, this);
				return;
			}
		}
	}

	FVector Location = GetActorLocation();
	SetActorLocation(FVector(Location.X - DeltaTime * speed, Location.Y, Location.Z));

	if (Armor)
	{
		Armor->SetActorLocation(GetActorLocation() + FVector(0, 1, 0));
	}
}

float AStandardZombie::Damage(float value, EDamageType damageType, AActor* source)
{
	if (Armor)
	{
		return(Super::Damage(Armor->Damage(value, damageType, source), damageType, source));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%"), Health);
		return(Super::Damage(value, damageType, source));
	}
}

void AStandardZombie::EndPlay(EEndPlayReason::Type reason)
{
	if (Armor != nullptr && reason == EEndPlayReason::Type::Destroyed) { Armor->Destroy(); }
	Super::EndPlay(reason);
}

void AStandardZombie::SetArmor(class ADamagableEquipment* armor)
{
	Armor = armor;
}