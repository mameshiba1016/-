#include "EnemyDemo.h"
#include "Enemy.h"
#include <iostream>
#include <memory>

namespace
{
    void UpdateAndDrawEnemy()
    {
        // この関数の中だけで敵を所有する。
        auto enemy = std::make_unique<Enemy>();
        enemy->Update();
        enemy->Draw();

        // 関数を抜けるとunique_ptrが破棄され、所有しているEnemyも自動で破棄される。
        std::cout << "敵を所有する関数を終了します。\n";
    }
}

void RunEnemyDemo()
{
    UpdateAndDrawEnemy();

    // この行より前に、Enemyのデストラクタのメッセージが表示される。
    std::cout << "呼び出し元へ戻りました。\n";
}
