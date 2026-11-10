#pragma once

class Enemy
{
public:
    Enemy();

    // HPを変更せずに、現在の値を取得・表示する。
    int GetHp() const;
    void Draw() const;

    // 戦闘不能かを判定し、攻撃時にはHPを更新する。
    bool IsDefeated() const;
    void TakeDamage(int damage);

private:
    int hp;
};
