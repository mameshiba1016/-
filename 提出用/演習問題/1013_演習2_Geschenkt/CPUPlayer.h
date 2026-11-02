#pragma once
#include "Player.h"
#include <string>

// CPUPlayerのデータと公開する操作を宣言する。
class CPUPlayer : public Player
{
public:
    explicit CPUPlayer(std::string name);
    // 行動を決定する。人間とCPUでは同じ関数名で異なる処理を行う。
    Action ChooseAction(int card, int pot) override;
};
