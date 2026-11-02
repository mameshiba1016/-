#include <iostream>
#include "Config.h"
#include "Inumaki.h"

// Inumakiの操作を実装する。
Inumaki::Inumaki() : Sorcerer(Config::INUMAKI_HP, Config::INUMAKI_ENERGY)
{
}

// Inumakiの操作を実装する。
void Inumaki::UseTechnique()
{
    std::cout << "狗巻棘：呪言を使用する\n";
}
