#include <iostream>
#include "Config.h"
#include "Sorcerer.h"

// Sorcererの操作を実装する。
Sorcerer::Sorcerer(int hp, int energy) : hp(hp), cursedEnergy(energy)
{
}

// Sorcererの操作を実装する。
void Sorcerer::ShowStatus() const
{
    std::cout << "HP：" << hp << " 呪力：" << cursedEnergy << '\n';
}

// 基底クラス経由でも安全に破棄できるよう、仮想デストラクタを実装する。
Sorcerer::~Sorcerer() = default;
