#pragma once
#include "Sorcerer.h"

// Gojoのデータと公開する操作を宣言する。
class Gojo : public Sorcerer
{
public:
    Gojo();
    // この呪術師に固有の術式を実行する。
    void UseTechnique() override;
};
