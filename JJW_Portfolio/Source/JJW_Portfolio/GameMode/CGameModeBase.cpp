#include "CGameModeBase.h"

ACGameModeBase::ACGameModeBase()
{
	ConstructorHelpers::FClassFinder<APawn>Player(L"/Script/Engine.Blueprint'/Game/Blueprint/Characters/Player/BP_CPlayer.BP_CPlayer_C'");
	if(!!Player.Class)
	DefaultPawnClass = Player.Class;
}
