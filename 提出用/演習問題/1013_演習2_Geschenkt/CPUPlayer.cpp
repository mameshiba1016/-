#include <utility>
#include "Config.h"
#include "CPUPlayer.h"

// CPUPlayerの操作を実装する。
CPUPlayer::CPUPlayer(std::string name) : Player(std::move(name))
{
}

// CPUPlayerの操作を実装する。
Action CPUPlayer::ChooseAction(int card, int pot)
{
    return AddedPoints(card) - pot <= Config::CPU_TAKE_THRESHOLD ||
                   GetChips() <= Config::CPU_LOW_CHIPS
               ? Action::Take
               : Action::Pass;
}
