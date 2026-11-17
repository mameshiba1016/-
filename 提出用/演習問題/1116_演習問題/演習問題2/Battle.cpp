#include "Battle.h"
#include "Config.h"
#include "Enemy.h"
#include <algorithm>
#include <array>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

namespace
{
    using EnemyList = std::array<std::shared_ptr<Enemy>, Config::ENEMY_COUNT>;

    void ShowHp(const EnemyList& enemies)
    {
        // 倒れた敵も一覧に残し、敵番号がずれないようにする。
        auto number = Config::FIRST_ENEMY_NUMBER;
        for (const auto& enemy : enemies)
        {
            std::cout << "敵" << number << " HP: " << enemy->GetHp();
            if (!enemy->IsAlive())
            {
                std::cout << "（撃破済み）";
            }
            std::cout << '\n';
            ++number;
        }
    }

    std::shared_ptr<Enemy> SelectTarget(const EnemyList& enemies)
    {
        while (true)
        {
            std::cout << "攻撃対象（" << Config::FIRST_ENEMY_NUMBER
                      << "～" << Config::ENEMY_COUNT << "）: ";
            std::string line;
            if (!std::getline(std::cin, line))
            {
                return nullptr;
            }

            // 入力全体を検査し、範囲外の値や数字の後ろに文字がある入力を拒否する。
            std::istringstream input(line);
            std::size_t number{};
            char extra{};
            if (!(input >> number) || (input >> extra) ||
                number < Config::FIRST_ENEMY_NUMBER || number > enemies.size())
            {
                std::cout << "範囲内の敵番号を入力してください。\n";
                continue;
            }

            // 番号を添字に変換してから、生存中の敵だけを攻撃対象にする。
            const auto& enemy = enemies[number - Config::FIRST_ENEMY_NUMBER];
            if (!enemy->IsAlive())
            {
                std::cout << "その敵は撃破済みです。別の敵を選んでください。\n";
                continue;
            }
            // 配列が敵を所有したまま、選ばれた敵の共有所有権を呼び出し元に渡す。
            return enemy;
        }
    }
}

void RunBattle()
{
    EnemyList enemies;
    for (auto& enemy : enemies)
    {
        // 要素ごとに生成するので、3つのポインタはそれぞれ別の敵を指す。
        enemy = std::make_shared<Enemy>();
    }

    ShowHp(enemies);
    // 生存中の敵がいなくなるまで、対象選択と攻撃を繰り返す。
    while (std::any_of(enemies.begin(), enemies.end(),
                       [](const auto& enemy) { return enemy->IsAlive(); }))
    {
        const auto target = SelectTarget(enemies);
        if (!target)
        {
            std::cout << "入力が終了したため、戦闘を終了します。\n";
            return;
        }
        target->Damage(Config::ATTACK_DAMAGE);
        std::cout << "選んだ敵に" << Config::ATTACK_DAMAGE << "ダメージ！\n";
        ShowHp(enemies);
    }
    std::cout << "すべての敵を倒しました。\n";
}
