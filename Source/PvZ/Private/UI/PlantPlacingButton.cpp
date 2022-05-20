
#include "UI/PlantPlacingButton.h"

void UPlantPlacingButton::OnClicked()
{
}

void UPlantPlacingButton::Setup(TSubclassOf<class APlantn> plantClass, float cooldown)
{
	PlantClass = plantClass;
	Cooldown = cooldown;
}

void UPlantPlacingButton::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	UUserWidget::NativeTick(MyGeometry, InDeltaTime);

	if (Cooldown == 0)
	{
		return;
	}

	Cooldown -= InDeltaTime;
	if (Cooldown < 0)
	{
		Cooldown = 0;
	}
}
