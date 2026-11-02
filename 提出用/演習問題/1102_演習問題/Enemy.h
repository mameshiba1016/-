#pragma once
#include "Config.h"
// 1102_演習問題 / Enemy.h
// 宣言とクラスの役割をまとめる。
#include "Action.h"

namespace Enemy
{
    // プレイヤーが攻撃を選んだときだけ、敵は防御する。
    bool IsDefending(Action playerAction);
    // 選択した行動を実行する。参照引数のHPを更新して呼び出し元へ反映する。
    void TakeAction(Action playerAction, int& playerHp);
} // namespace Enemy
