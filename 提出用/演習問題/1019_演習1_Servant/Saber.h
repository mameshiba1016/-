#pragma once
// 1019_演習1_Servant / Saber.h
// 宣言とクラスの役割をまとめる。
using namespace std;
#include "Servant.h"

// 剣士の攻撃とプロフィールを実装する。
class Saber : public Servant
{
public:
    // このクラスに対応する攻撃を実行する。
    void Attack() override;
    // このクラスに対応するプロフィールを表示する。
    void ShowProfile() override;
};
