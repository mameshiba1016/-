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

// 正のダメージだけをHPから引く。0以下のHPは後で削除判定に使う。
void Enemy::Damage(int damage)
{
    if (damage > Config::DEFEATED_HP)
    {
        hp -= damage;
    }
}

// 削除判定などに使うため、HPを変更せず現在値を返す。
int Enemy::GetHp() const
{
    return hp;
}
