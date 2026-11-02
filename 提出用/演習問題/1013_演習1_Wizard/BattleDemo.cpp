#include "BattleDemo.h"
#include "Character.h"
#include "Wizard.h"

int RunBattleDemo()
{
    Wizard wizard;
    Character* character = &wizard;
    character->Attack();
    return 0;
}
