#include <iostream>
#include "MagicalGirl.h"

// MagicalGirlの操作を実装する。
void MagicalGirl::ShowProfile()
{
    std::cout << "魔法少女のプロフィール\n";
}

// 基底クラス経由でも安全に破棄できるよう、仮想デストラクタを実装する。
MagicalGirl::~MagicalGirl() = default;
