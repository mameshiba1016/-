#include "EnemyDemo.h"
#include "Enemy.h"
#include <iostream>

// 敵をconst参照で借りる。コピーも所有権の移動も行わない。
void ShowEnemy(const Enemy& enemy)
{
    std::cout << "ShowEnemyから表示: HP: " << enemy.GetHp() << '\n';
}

int main()
{
    RunEnemyDemo();
}
