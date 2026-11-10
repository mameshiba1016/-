#pragma once

class Enemy
{
public:
    Enemy();

    // HPを変更せずに、現在の値を取得・表示する。
    int GetHp() const;
    void Draw() const;

private:
    int hp;
};
