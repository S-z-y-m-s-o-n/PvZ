
#include "UI/PlantPlacingButton.h"

void UPlantPlacingButton::OnClicked()
{
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
