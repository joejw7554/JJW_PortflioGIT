#include "CGameModeBase.h"

ACGameModeBase::ACGameModeBase()
{
	ConstructorHelpers::FClassFinder<APawn>Player(TEXT("/Script/Engine.Blueprint'/Game/Blueprint/Characters/BP_CPlayer.BP_CPlayer_C'"));
	if(!!Player.Class)
	DefaultPawnClass = Player.Class;
}
