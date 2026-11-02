#pragma once
// 1019_演習1_Servant / Rider.h
// 宣言とクラスの役割をまとめる。
using namespace std;
#include "Servant.h"

// 騎兵の攻撃とプロフィールを実装する。
class Rider : public Servant
{
public:
    // このクラスに対応する攻撃を実行する。
    void Attack() override;
    // このクラスに対応するプロフィールを表示する。
    void ShowProfile() override;
};
