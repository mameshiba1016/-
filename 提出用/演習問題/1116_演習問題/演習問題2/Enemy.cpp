#include "Enemy.h"
#include "Config.h"
#include <algorithm>

Enemy::Enemy() : hp(Config::INITIAL_HP)
{
}

void Enemy::Damage(int damage)
{
    // 残りHPより大きいダメージでも、HPは0で止める。
    hp = std::max(Config::DEFEATED_HP, hp - damage);
}

int Enemy::GetHp() const
{
    return hp;
}

bool Enemy::IsAlive() const
{
    return hp > Config::DEFEATED_HP;
}
