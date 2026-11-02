#pragma once

// Sorcererのデータと公開する操作を宣言する。
class Sorcerer
{
private:
    int hp;
    int cursedEnergy;

public:
    Sorcerer(int hp, int energy);
    virtual ~Sorcerer();
    // 保持しているステータスを表示する。
    void ShowStatus() const;
    // この呪術師に固有の術式を実行する。
    virtual void UseTechnique() = 0;
};
