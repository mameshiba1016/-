#include "Config.h"
#include "EnemyDemo.h"
// 1027_演習問題 / Main.cpp
// 処理の流れと各操作の意図をコメントで示す。
#include "Enemy.h"
#include <iostream>
#include <random>
#include <vector>
#include <limits>

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
    // 敵の番号は1から3。入力した番号をvectorの添字に変換する。
    std::size_t targetNumber = 0;
    while (true)
    {
        std::cout << "ダメージを与える敵の番号（1～3）: ";
        if (std::cin >> targetNumber && targetNumber >= Config::FIRST_ENEMY_NUMBER &&
            targetNumber <= enemies.size())
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        if (std::cin.eof())
        {
            std::cout << "入力が終了したため終了します。" << std::endl;
            return 0;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "1～3の番号を入力してください。" << std::endl;
    }
    // ダメージも範囲の両端を含む20～90から決める。
    std::uniform_int_distribution<int> damageDistribution(Config::MIN_DAMAGE, Config::MAX_DAMAGE);
    const int damage = damageDistribution(generator);
    enemies[targetNumber - Config::FIRST_ENEMY_NUMBER].Damage(damage);
    std::cout << "敵" << targetNumber << "に" << damage << "のダメージ！" << std::endl;
    std::cout << "ダメージ後の全員のHP" << std::endl;
    for (std::size_t i = 0; i < enemies.size(); ++i)
    {
        std::cout << "敵" << i + 1 << " ";
        enemies[i].ShowHp();
    }
    // eraseの戻り値を使い、削除後の無効なイテレータを使わない。
    for (auto it = enemies.begin(); it != enemies.end();)
    {
        if (it->GetHp() <= Config::DEFEATED_HP)
        {
            it = enemies.erase(it);
        }
        else
        {
            ++it;
        }
    }
    std::cout << "削除後の敵のHP" << std::endl;
    for (const Enemy& enemy : enemies)
    {
        enemy.ShowHp();
    }
    std::cout << "残った敵の数: " << enemies.size() << std::endl;
    return 0;
}
