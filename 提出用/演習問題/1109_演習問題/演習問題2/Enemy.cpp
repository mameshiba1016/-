#include "Enemy.h"
#include "Config.h"
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
