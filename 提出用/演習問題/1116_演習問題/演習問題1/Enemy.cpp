#include "Enemy.h"
#include <iostream>
#include <utility>

Enemy::Enemy(std::string name) : name(std::move(name))
{
}

void Enemy::ShowInfo() const
{
    std::cout << "敵の名前: " << name << '\n';
}
