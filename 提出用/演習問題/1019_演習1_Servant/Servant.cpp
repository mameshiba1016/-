// 1019_演習1_Servant / Servant.cpp
// 処理の流れと各操作の意図をコメントで示す。
#include <iostream>
#include "Servant.h"
using namespace std;

// このクラスに対応する攻撃を実行する。
void Servant::Attack()
{
    cout << "攻撃" << endl;
}

// このクラスに対応するプロフィールを表示する。
void Servant::ShowProfile()
{
    cout << "サーヴァントのプロフィール" << endl;
}

Servant::~Servant() = default;
