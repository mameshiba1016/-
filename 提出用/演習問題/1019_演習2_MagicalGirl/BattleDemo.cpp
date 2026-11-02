#include "BattleDemo.h"
#include "MagicalGirl.h"
#include "Madoka.h"
#include "Homura.h"

int RunBattleDemo()
{
    Madoka madoka;
    Homura homura;
    // 基底クラスのポインタでまとめ、種類ごとの分岐なしで呼び出す。
    MagicalGirl* girls[] = {&madoka, &homura};
    for (MagicalGirl* girl : girls)
    {
        girl->Fight();
        girl->ShowProfile();
    }
    return 0;
}
