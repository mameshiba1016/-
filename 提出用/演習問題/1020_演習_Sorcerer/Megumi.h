#pragma once
#include "Sorcerer.h"

// Megumiのデータと公開する操作を宣言する。
class Megumi : public Sorcerer
{
public:
    Megumi();
    // この呪術師に固有の術式を実行する。
    void UseTechnique() override;
};
