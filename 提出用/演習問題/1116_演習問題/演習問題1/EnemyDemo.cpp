#include "EnemyDemo.h"
#include "Enemy.h"
#include <iostream>
#include <memory>

void RunEnemyDemo()
{
    // make_sharedで敵を作り、この変数が共有所有権を持つ。
    const auto enemy = std::make_shared<Enemy>("スライム");
    enemy->ShowInfo();

    // shared_ptrをコピーしていないので、この時点の所有者はこの変数だけ。
    std::cout << "現在の所有者数: " << enemy.use_count() << '\n';
}
