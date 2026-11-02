#pragma once
#include "MagicalGirl.h"

// Madokaのデータと公開する操作を宣言する。
class Madoka : public MagicalGirl
{
public:
    // 実際のオブジェクトに対応する戦闘行動を実行する。
    void Fight() override;
};
