#include "EnemyDemo.h"
#include "Enemy.h"
#include <iostream>
#include <memory>

void RunEnemyDemo()
{
    auto enemy = std::make_unique<Enemy>();

    std::cout << "生成直後: ";
    enemy->Draw();

    // *enemyは所有しているEnemy自身。unique_ptrはここで移動しない。
    ShowEnemy(*enemy);

    // 呼び出し後も同じEnemyを表示できることを確認する。
    std::cout << "ShowEnemy呼び出し後: ";
    enemy->Draw();
}
