
#include "Plants/PoisonousBerry.h"

#include "PaperFlipbookComponent.h"
#include "Plants/PoisonousBerry.h"
#include "Game/GridCell.h"

#include "Game/Damage.h"

#define Fruit1 Fruit1a
#define Fruit2 Fruit2a
#define Fruit3 Fruit3a

APoisonousBerry::APoisonousBerry()
{
	PrimaryActorTick.bCanEverTick = true;
	Fruit1 = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Fruit1"));
	Fruit2 = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Fruit2"));
	Fruit3 = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Fruit3"));

	Fruit1->SetupAttachment(SpriteComponent);
	Fruit2->SetupAttachment(SpriteComponent);
	Fruit3->SetupAttachment(SpriteComponent);

	Fruits.Add(Fruit1);
	Fruits.Add(Fruit2);
	Fruits.Add(Fruit3);
}

void APoisonousBerry::UpdateFruits()
{
	for (int i = 0; i <= 2; i++)
	{
		if (Fruits[i] != nullptr)
		{
			Fruits[i]->SetVisibility(FruitStatus[i]);
		}
	}
}

float APoisonousBerry::Damage(float value, EDamageType damageType, AActor* source)
{
	for (int i = 0; i <= 2; i++)
	{
		if (FruitStatus[i] == true)
		{
			FruitHealth[i] -= value;
			if (FruitHealth[i] <= 0)
			{
				FruitStatus[i] = false;
				value = abs(FruitHealth[i]);
				FruitHealth[i] = 0;
				if (damageType == EDamageType::Eating)
				{
					((AFightingActor*)source)->Damage(-1.f, EDamageType::Poison, this);
					return 0;
				}
				UpdateFruits();
				if (value == 0) { return 0; }
			}
			else { return 0; }
		}
	}
	UpdateFruits();
	if (value > 0)
	{
		return(Super::Damage(value, damageType, source));
	}
	return 0;
}

void APoisonousBerry::Tick(float DeltaTime)
{
	if (isPlanted)
	{
		float value = DeltaTime * MaxFruitHealth / FruitRegrowthTime;
		for (int i = 0; i <= 2; i++)
		{
			if (FruitStatus[i] == false)
			{
				FruitHealth[i] += value;
				if (FruitHealth[i] >= MaxFruitHealth)
				{
					FruitStatus[i] = true;
					value = FruitHealth[i] - MaxFruitHealth;
					FruitHealth[i] = MaxFruitHealth;
					UpdateFruits();
					if (value == 0) { return; }
				}
				else { return; }
			}
		}
		for (int i = 0; i <= 2; i++)
		{
			if (FruitHealth[i] < MaxFruitHealth)
			{
				FruitHealth[i] += value;
				if (FruitHealth[i] > MaxFruitHealth)
				{
					value = FruitHealth[i] - MaxFruitHealth;
				}
				else { UpdateFruits(); return; }
			}
		}
		UpdateFruits();
	}
}

void APoisonousBerry::BeginPlay()
{
	Super::BeginPlay();
}
