#pragma once

// 1019_演習1_Servant / Servant.h
// 宣言とクラスの役割をまとめる。
// 共通の呼び出し方を定義し、攻撃の実装を派生クラスに求める。
class Servant
{
public:
    virtual ~Servant();
    // 純粋仮想関数
    /// <summary>
    /// 攻撃処理
    /// </summary>
    // このクラスに対応する攻撃を実行する。
    virtual void Attack() = 0;
    /// <summary>
    /// プロフィール関数
    /// </summary>
    // このクラスに対応するプロフィールを表示する。
    virtual void ShowProfile();
};
