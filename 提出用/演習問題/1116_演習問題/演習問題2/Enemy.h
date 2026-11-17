#pragma once

class Enemy
{
public:
    Enemy();
    void Damage(int damage);
    int GetHp() const;
    bool IsAlive() const;

private:
    int hp;
};
