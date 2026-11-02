#include "Config.h"
// 1102_演習問題 / Enemy.cpp
// 処理の流れと各操作の意図をコメントで示す。
#include "Enemy.h"
#include <iostream>

// プレイヤーが攻撃を選んだときだけ、敵は防御する。
bool Enemy::IsDefending(Action playerAction)
{
    return playerAction == Action::Attack;
}

// 選択した行動を実行する。参照引数のHPを更新して呼び出し元へ反映する。
void Enemy::TakeAction(Action playerAction, int& playerHp)
{
    if (IsDefending(playerAction))
    {
        // このターンは防御。攻撃を追加では行わない。
        return;
    }
    const int damage =
        playerAction == Action::Defend ? Config::DEFENDING_DAMAGE : Config::ENEMY_ATTACK_DAMAGE;
    playerHp -= damage;
    std::cout << "敵の攻撃！ プレイヤーに" << damage << "ダメージ！" << std::endl;
}
