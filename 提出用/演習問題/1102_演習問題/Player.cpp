#include "Config.h"
// 1102_演習問題 / Player.cpp
// 処理の流れと各操作の意図をコメントで示す。
#include "Player.h"
#include <iostream>
#include <sstream>
#include <string>

// 有効な入力なら行動を参照引数へ格納する。入力終了ならfalseを返す。
bool Player::ChooseAction(Action& action)
{
    while (true)
    {
        std::cout << "1: 攻撃  2: 防御  3: 回復 > ";
        std::string line;
        if (!std::getline(std::cin, line))
        {
            return false;
        }
        std::istringstream input(line);
        int number = 0;
        char extra = 0;
        // 数字の後ろに余分な文字がある入力（例: 1abc）も受け付けない。
        if ((input >> number) && !(input >> extra) && number >= static_cast<int>(Action::Attack) &&
            number <= static_cast<int>(Action::Heal))
        {
            action = static_cast<Action>(number);
            return true;
        }
        std::cout << "1、2、3のいずれかを入力してください。" << std::endl;
    }
}

// 選択した行動を実行する。参照引数のHPを更新して呼び出し元へ反映する。
void Player::TakeAction(Action action, int& hp, int& enemyHp, bool enemyDefending)
{
    switch (action)
    {
    case Action::Attack:
        std::cout << "プレイヤーの攻撃！" << std::endl;
        if (enemyDefending)
        {
            std::cout << "敵は防御した！ ダメージは0。" << std::endl;
        }
        else
        {
            enemyHp -= Config::PLAYER_ATTACK_DAMAGE;
            std::cout << "敵に" << Config::PLAYER_ATTACK_DAMAGE << "ダメージ！" << std::endl;
        }
        break;
    case Action::Defend:
        std::cout << "プレイヤーは防御した！" << std::endl;
        break;
    case Action::Heal:
        // 回復上限の指定はないため、現在のHPに20を加える。
        hp += Config::HEAL_AMOUNT;
        std::cout << "プレイヤーのHPが" << Config::HEAL_AMOUNT << "回復！" << std::endl;
        break;
    }
}
