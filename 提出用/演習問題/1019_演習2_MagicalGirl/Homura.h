#pragma once
#include "MagicalGirl.h"

// Homuraのデータと公開する操作を宣言する。
class Homura : public MagicalGirl
{
public:
    // 実際のオブジェクトに対応する戦闘行動を実行する。
    void Fight() override;
    // このクラスに対応するプロフィールを表示する。
    void ShowProfile() override;
};
