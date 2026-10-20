#include <iostream>
class Sorcerer {
private: int hp; int cursedEnergy;
public:
 Sorcerer(int hp, int energy) : hp(hp), cursedEnergy(energy) {}
 virtual ~Sorcerer() = default;
 void ShowStatus() const { std::cout << "HP：" << hp << " 呪力：" << cursedEnergy << '\n'; }
 virtual void UseTechnique() = 0;
};
class Megumi : public Sorcerer { public: Megumi():Sorcerer(100,80) {} void UseTechnique() override { std::cout << "伏黒恵：式神を召喚する\n"; } };
class Inumaki : public Sorcerer { public: Inumaki():Sorcerer(90,70) {} void UseTechnique() override { std::cout << "狗巻棘：呪言を使用する\n"; } };
class Gojo : public Sorcerer { public: Gojo():Sorcerer(999,999) {} void UseTechnique() override { std::cout << "五条悟：六眼・無下限術式、領域展開を使用する\n"; } };
int main() { Megumi megumi; Inumaki inumaki; Gojo gojo; Sorcerer* sorcerers[]={&megumi,&inumaki,&gojo}; for(auto* sorcerer:sorcerers) { sorcerer->ShowStatus(); sorcerer->UseTechnique(); } }
