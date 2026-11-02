#include <iostream>
#include <string>
#include "Config.h"
#include "HumanPlayer.h"

// HumanPlayerの操作を実装する。
HumanPlayer::HumanPlayer() : Player("あなた")
{
}

// HumanPlayerの操作を実装する。
Action HumanPlayer::ChooseAction(int, int)
{
    for (;;)
    {
        std::cout << "1：取る  2：チップを払う > ";
        std::string line;
        if (!std::getline(std::cin, line))
        {
            std::cout << "入力終了のため取ります。\n";
            return Action::Take;
        }
        if (line == Config::TAKE_INPUT)
            return Action::Take;
        if (line == Config::PASS_INPUT)
            return Action::Pass;
        std::cout << "1または2を入力してください。\n";
    }
}
