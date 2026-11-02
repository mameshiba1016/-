#include "Config.h"
#include "Battle.h"
// 1102_演習問題 / Main.cpp
// 処理の流れと各操作の意図をコメントで示す。
#include "Player.h"
#include "Enemy.h"
#include <iostream>

namespace
{
    // 保持しているステータスを表示する。
    void ShowStatus(int playerHp, int enemyHp)
    {
        std::cout << "プレイヤーHP: " << playerHp << " / 敵HP: " << enemyHp << std::endl;
    }
} // namespace

// オブジェクトの準備と処理の呼び出しを行う、プログラムの入口。
int RunBattle()
{
    int playerHp = Config::INITIAL_PLAYER_HP;
    int enemyHp = Config::INITIAL_ENEMY_HP;
    std::cout << "コマンドバトル開始！" << std::endl;
    ShowStatus(playerHp, enemyHp);
    // どちらかのHPが0以下になるまで、入力・プレイヤー行動・敵行動を繰り返す。
    while (playerHp > Config::DEFEATED_HP && enemyHp > Config::DEFEATED_HP)
    {
        Action action = Action::Attack;
        if (!Player::ChooseAction(action))
        {
            std::cout << "入力が終了したためゲームを終了します。" << std::endl;
            return 0;
        }
        // 敵の防御をプレイヤーの攻撃より先に決める。
        const bool enemyDefending = Enemy::IsDefending(action);
        Player::TakeAction(action, playerHp, enemyHp, enemyDefending);
        if (enemyHp > Config::DEFEATED_HP)
        {
            Enemy::TakeAction(action, playerHp);
        }
        ShowStatus(playerHp, enemyHp);
        std::cout << std::endl;
    }
    if (enemyHp <= Config::DEFEATED_HP)
    {
        std::cout << "プレイヤーの勝利！" << std::endl;
    }
    else
    {
        std::cout << "プレイヤーの敗北……" << std::endl;
    }
    return 0;
}
