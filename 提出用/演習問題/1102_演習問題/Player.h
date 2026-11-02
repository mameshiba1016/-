#pragma once
#include "Config.h"
// 1102_演習問題 / Player.h
// 宣言とクラスの役割をまとめる。
#include "Action.h"

namespace Player
{
    // 有効な入力なら行動を参照引数へ格納する。入力終了ならfalseを返す。
    bool ChooseAction(Action& action);
    // 選択した行動を実行する。参照引数のHPを更新して呼び出し元へ反映する。
    void TakeAction(Action action, int& hp, int& enemyHp, bool enemyDefending);
} // namespace Player
