#include "BattleDemo.h"
// 1019_演習1_Servant / Main.cpp
// 処理の流れと各操作の意図をコメントで示す。
#include "Saber.h"
#include "Archer.h"
#include "Rider.h"

// オブジェクトの準備と処理の呼び出しを行う、プログラムの入口。
int RunBattleDemo()
{
    Saber saber;
    Archer archer;
    Rider rider;
    // 基底クラスのポインタでまとめ、種類ごとの分岐なしで呼び出す。
    Servant* servants[] = {&saber, &archer, &rider};
    for (Servant* servant : servants)
    {
        servant->ShowProfile();
        servant->Attack();
    }
    return 0;
    return 0;
}
