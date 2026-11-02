#pragma once
#include "Config.h"

// 1027_演習問題 / Enemy.h
// 宣言とクラスの役割をまとめる。
// 敵のHPを保持する。HPの表示や変更は公開した関数から行う。
class Enemy
{
private:
    int hp;

public:
    // 生成時に渡された値を、この敵の初期HPとして保持する。
    explicit Enemy(int hp);
    // 現在のHPを表示する。オブジェクトの状態は変更しない。
    void ShowHp() const;
    // 正のダメージだけをHPから引く。0以下のHPは後で削除判定に使う。
    void Damage(int damage);
    // 削除判定などに使うため、HPを変更せず現在値を返す。
    int GetHp() const;
};
