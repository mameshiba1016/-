// 1019_演習1_Servant / Saber.cpp
// 処理の流れと各操作の意図をコメントで示す。
#include <iostream>
#include "Saber.h"
using namespace std;

// このクラスに対応する攻撃を実行する。
void Saber::Attack()
{
    cout << "剣で攻撃する" << endl;
}

// このクラスに対応するプロフィールを表示する。
void Saber::ShowProfile()
{
    cout << "セイバー" << endl;
}
