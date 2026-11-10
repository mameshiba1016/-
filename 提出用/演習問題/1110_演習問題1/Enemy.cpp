#include "Enemy.h"
#include "Config.h"
#include <algorithm>
#include <iostream>

Enemy::Enemy() : hp(Config::INITIAL_HP)
{
}

int Enemy::GetHp() const
{
    return hp;
}

void Enemy::Draw() const
{
    std::cout << "HP: " << hp << '\n';
}

bool Enemy::IsDefeated() const
{
    return hp <= Config::DEFEATED_HP;
}

void Enemy::TakeDamage(int damage)
{
    // 残りHPより大きなダメージでも、表示するHPは0で止める。
    hp = std::max(Config::DEFEATED_HP, hp - damage);
}
