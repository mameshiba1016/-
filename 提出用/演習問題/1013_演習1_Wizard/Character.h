#pragma once

// Characterのデータと公開する操作を宣言する。
class Character
{
public:
    virtual ~Character();
    // このクラスに対応する攻撃を実行する。
    virtual void Attack();
};
