#include "Config.h"
#include "EnemyDemo.h"
// 1027_演習問題 / Main.cpp
// 処理の流れと各操作の意図をコメントで示す。
#include "Enemy.h"
#include <iostream>
#include <random>
#include <vector>

// オブジェクトの準備と処理の呼び出しを行う、プログラムの入口。
int RunEnemyDemo()
{
    std::mt19937 generator(std::random_device{}());
    // 範囲の両端を含む30～100から、各敵の初期HPを作る。
    std::uniform_int_distribution<int> hpDistribution(Config::MIN_HP, Config::MAX_HP);
    std::vector<Enemy> enemies;
    for (int i = 0; i < Config::ENEMY_COUNT; ++i)
    {
        enemies.emplace_back(hpDistribution(generator));
    }
    std::cout << "敵のHP" << std::endl;
    for (std::size_t i = 0; i < enemies.size(); ++i)
    {
        std::cout << "敵" << i + 1 << " ";
        enemies[i].ShowHp();
    }
    return 0;
}
