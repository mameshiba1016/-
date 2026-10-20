#include <iostream>
class MagicalGirl { public: virtual ~MagicalGirl() = default; virtual void Fight() = 0; virtual void ShowProfile() { std::cout << "魔法少女のプロフィール\n"; } };
class Madoka : public MagicalGirl { public: void Fight() override { std::cout << "まどか：弓の攻撃！\n"; } };
class Homura : public MagicalGirl { public: void Fight() override { std::cout << "ほむら：時間停止を利用して戦う！\n"; } void ShowProfile() override { std::cout << "ほむら：時間を操る魔法少女\n"; } };
int main() { Madoka madoka; Homura homura; MagicalGirl* girls[]={&madoka,&homura}; for(int i=0;i<2;++i) { girls[i]->Fight(); girls[i]->ShowProfile(); } }
