#include "EnemyDemo.h"
#include "Config.h"
#include "Enemy.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <sstream>
#include <string>

namespace
{
    using Enemies = std::array<Enemy, Config::ENEMY_COUNT>;

    void ShowAllHp(const Enemies& enemies)
    {
        // 倒した敵も配列から消さず、敵番号とHPの対応を保つ。
        for (std::size_t index = 0; index < enemies.size(); ++index)
        {
            std::cout << "敵" << index + Config::FIRST_ENEMY_NUMBER << " ";
            enemies[index].Draw();
        }
    }

    bool SelectTarget(const Enemies& enemies, std::size_t& targetIndex)
    {
        const auto lastEnemyNumber = Config::FIRST_ENEMY_NUMBER + enemies.size() - 1;
        while (true)
        {
            std::cout << "攻撃する敵を選んでください（" << Config::FIRST_ENEMY_NUMBER
                      << "～" << lastEnemyNumber << "）: ";

            std::string line;
            if (!std::getline(std::cin, line))
            {
                return false;
            }

            // 1行を丸ごと調べ、範囲外の数字や「1abc」のような入力を拒否する。
            std::istringstream input(line);
            std::size_t enemyNumber = 0;
            char extra = '\0';
            if (!(input >> enemyNumber) || (input >> extra) ||
                enemyNumber < Config::FIRST_ENEMY_NUMBER || enemyNumber > lastEnemyNumber)
            {
                std::cout << "表示された範囲の敵番号を入力してください。\n";
                continue;
            }

            // 表示番号を配列の添字に直してから、攻撃可能かを確認する。
            const auto index = enemyNumber - Config::FIRST_ENEMY_NUMBER;
            if (enemies[index].IsDefeated())
            {
                std::cout << "その敵はすでに倒れています。別の敵を選んでください。\n";
                continue;
            }
            targetIndex = index;
            return true;
        }
    }
}

void RunEnemyDemo()
{
    // 配列の各要素がEnemyのコンストラクタで初期化される。
    Enemies enemies{};
    std::cout << "戦闘開始時のHP\n";
    ShowAllHp(enemies);

    // 倒した敵を選べないことが確認できるよう、全滅するまで攻撃を繰り返す。
    while (std::any_of(enemies.begin(), enemies.end(),
                       [](const Enemy& enemy) { return !enemy.IsDefeated(); }))
    {
        std::size_t targetIndex = 0;
        if (!SelectTarget(enemies, targetIndex))
        {
            std::cout << "入力が終了したため戦闘を終了します。\n";
            return;
        }

        enemies[targetIndex].TakeDamage(Config::ATTACK_DAMAGE);
        std::cout << "敵" << targetIndex + Config::FIRST_ENEMY_NUMBER << "に"
                  << Config::ATTACK_DAMAGE << "ダメージ！\n";
        std::cout << "攻撃後のHP\n";
        ShowAllHp(enemies);
    }

    std::cout << "すべての敵を倒しました。\n";
}
