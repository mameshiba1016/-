// 1019_演習1_Servant / Rider.cpp
// 処理の流れと各操作の意図をコメントで示す。
#include "Rider.h"
#include <iostream>

// このクラスに対応する攻撃を実行する。
void Rider::Attack()
{
    std::cout << "騎乗して突撃する" << std::endl;
}

// このクラスに対応するプロフィールを表示する。
void Rider::ShowProfile()
{
    std::cout << "ライダー" << std::endl;
}
