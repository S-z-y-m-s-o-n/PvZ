
#include "Plants/Sunflower.h"

#include "Game/GridCell.h"

#include "Game/PvEBaseLevelGameMode.h"

#include "Kismet/GameplayStatics.h"

void ASunflower::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(Timer, this, &ASunflower::SpawnSun, 22, true);
}


void ASunflower::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorldTimerManager().ClearTimer(Timer);
}


void ASunflower::SpawnSun()
{
	Cast<APvEBaseLevelGameMode>(UGameplayStatics::GetActorOfClass(GetWorld(), APvEBaseLevelGameMode::StaticClass()))->SunCount += 2;
}
