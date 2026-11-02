#include "Config.h"
// 1027_演習問題 / Enemy.cpp
// 処理の流れと各操作の意図をコメントで示す。
#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int hp) : hp(hp)
{
}

// 現在のHPを表示する。オブジェクトの状態は変更しない。
void Enemy::ShowHp() const
{
    std::cout << "HP: " << hp << std::endl;
}
