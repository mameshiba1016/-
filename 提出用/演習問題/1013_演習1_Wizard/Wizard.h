#pragma once
#include "Character.h"

// Wizardのデータと公開する操作を宣言する。
class Wizard : public Character
{
public:
    // このクラスに対応する攻撃を実行する。
    void Attack() override;
};
