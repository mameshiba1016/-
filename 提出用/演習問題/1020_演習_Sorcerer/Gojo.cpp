#include <iostream>
#include "Config.h"
#include "Gojo.h"

// Gojoの操作を実装する。
Gojo::Gojo() : Sorcerer(Config::GOJO_HP, Config::GOJO_ENERGY)
{
}

// Gojoの操作を実装する。
void Gojo::UseTechnique()
{
    std::cout << "五条悟：六眼・無下限術式、領域展開を使用する\n";
}
