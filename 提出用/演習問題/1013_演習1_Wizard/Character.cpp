#include <iostream>
#include "Character.h"

// Characterの操作を実装する。
void Character::Attack()
{
    std::cout << "通常攻撃\n";
}

// 基底クラス経由でも安全に破棄できるよう、仮想デストラクタを実装する。
Character::~Character() = default;
