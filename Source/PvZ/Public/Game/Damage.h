
#pragma once

#include "CoreMinimal.h"

UENUM()
enum class EDamageType : uint8
{
	Eating, 
	Poison,
	Fire,
	Electricity,
	Other
};
