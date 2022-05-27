
#include "Game/FightingActor.h"

#include "PaperFlipbookComponent.h"

AFightingActor::AFightingActor()
{
	SpriteComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite"));
	SetRootComponent(SpriteComponent);
}