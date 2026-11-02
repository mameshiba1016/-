// 1019_演習1_Servant / Archer.cpp
// 処理の流れと各操作の意図をコメントで示す。
#include "Archer.h"
#include <iostream>

// このクラスに対応する攻撃を実行する。
void Archer::Attack()
{
    std::cout << "弓で攻撃する" << std::endl;
}

// このクラスに対応するプロフィールを表示する。
void Archer::ShowProfile()
{
    std::cout << "アーチャー" << std::endl;
}
