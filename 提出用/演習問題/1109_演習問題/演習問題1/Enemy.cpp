#include "Enemy.h"
#include <iostream>

Enemy::~Enemy()
{
    std::cout << "Enemyを破棄しました。\n";
}

void Enemy::Update()
{
    // この演習では、更新処理が呼ばれたことを表示する。
    std::cout << "EnemyのUpdateを実行しました。\n";
}

void Enemy::Draw() const
{
    std::cout << "EnemyのDrawを実行しました。\n";
}
