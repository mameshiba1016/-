#pragma once
#include "Sorcerer.h"

// Inumakiのデータと公開する操作を宣言する。
class Inumaki : public Sorcerer
{
public:
    Inumaki();
    // この呪術師に固有の術式を実行する。
    void UseTechnique() override;
};
