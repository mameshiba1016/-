#pragma once

// MagicalGirlのデータと公開する操作を宣言する。
class MagicalGirl
{
public:
    virtual ~MagicalGirl();
    // 実際のオブジェクトに対応する戦闘行動を実行する。
    virtual void Fight() = 0;
    // このクラスに対応するプロフィールを表示する。
    virtual void ShowProfile();
};
