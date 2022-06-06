
#include "Enemies/Equipment/DamagableEquipment.h"

#include "Game/FightingActor.h"
#include "Enemies/Equipment/DamagableEquipment.h"

float ADamagableEquipment::Damage(float value, EDamageType damageType, AActor* source)
{
	if (value == -1) { return -1; }
	Health -= value;
	UE_LOG(LogTemp, Warning, TEXT("%"), Health);
	if (Health <= 0)
	{
		Destroy();
		return abs(Health);
	}
	return 0.0f;
}

void ADamagableEquipment::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
}