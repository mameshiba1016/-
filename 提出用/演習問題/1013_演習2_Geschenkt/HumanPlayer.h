#pragma once
#include "Player.h"

// HumanPlayerのデータと公開する操作を宣言する。
class HumanPlayer : public Player
{
public:
    HumanPlayer();
    // 行動を決定する。人間とCPUでは同じ関数名で異なる処理を行う。
    Action ChooseAction(int, int) override;
};
