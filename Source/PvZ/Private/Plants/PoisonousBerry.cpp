
#include "Plants/PoisonousBerry.h"

#include "PaperFlipbookComponent.h"
#include "Plants/PoisonousBerry.h"
#include "Game/GridCell.h"

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

void APoisonousBerry::Damage(float value)
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
				UpdateFruits();
				if (value == 0) { return; }
			}
			else { return; }
		}
	}
	UpdateFruits();
	if (value > 0)
	{
		Super::Damage(value);
	}
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
