#include <iostream>
class Character { public: virtual ~Character() = default; virtual void Attack() { std::cout << "通常攻撃\n"; } };
class Player : public Character { public: void Attack() override { std::cout << "剣で攻撃\n"; } };
class Enemy : public Character { public: void Attack() override { std::cout << "かみつき攻撃\n"; } };
class Boss : public Character { public: void Attack() override { std::cout << "強力な魔法で攻撃する\n"; } };
class Wizard : public Character { public: void Attack() override { std::cout << "魔法で攻撃する\n"; } };
int main() { Wizard wizard; Character* character = &wizard; character->Attack(); }
