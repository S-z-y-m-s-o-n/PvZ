
#include "UI/PlantSlot.h"

#include "Plants/Plant.h"

void UPlantSlot::OnClicked()
{
}

void UPlantSlot::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
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