#include "Config.h"
#include "BattleDemo.h"
#include "Sorcerer.h"
#include "Megumi.h"
#include "Inumaki.h"
#include "Gojo.h"

int RunBattleDemo()
{
    Megumi megumi;
    Inumaki inumaki;
    Gojo gojo;
    // 基底クラスのポインタでまとめ、種類ごとの分岐なしで呼び出す。
    Sorcerer* sorcerers[] = {&megumi, &inumaki, &gojo};
    for (auto* sorcerer : sorcerers)
    {
        sorcerer->ShowStatus();
        sorcerer->UseTechnique();
    }
    return 0;
}
