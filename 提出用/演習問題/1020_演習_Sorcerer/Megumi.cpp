#include <iostream>
#include "Config.h"
#include "Megumi.h"

// Megumiの操作を実装する。
Megumi::Megumi() : Sorcerer(Config::MEGUMI_HP, Config::MEGUMI_ENERGY)
{
}

// Megumiの操作を実装する。
void Megumi::UseTechnique()
{
    std::cout << "伏黒恵：式神を召喚する\n";
}
