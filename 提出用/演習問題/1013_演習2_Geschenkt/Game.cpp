#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include "Config.h"
#include "HumanPlayer.h"
#include "CPUPlayer.h"
#include "Config.h"
#include "Game.h"

// Gameの操作を実装する。
void Game::Initialize()
{
    players.clear();
    players.push_back(std::make_unique<HumanPlayer>());
    players.push_back(std::make_unique<CPUPlayer>("CPU1"));
    players.push_back(std::make_unique<CPUPlayer>("CPU2"));
    deck.resize(Config::CARD_COUNT);
    std::iota(deck.begin(), deck.end(), Config::MIN_CARD);
    std::mt19937 generator(std::random_device{}());
    std::shuffle(deck.begin(), deck.end(), generator);
    deck.resize(Config::USED_CARD_COUNT);
}

// Gameの操作を実装する。
void Game::Run()
{
    Initialize();
    std::size_t turn = 0;
    for (int card : deck)
    {
        int pot = 0;
        std::cout << "\n公開カード：" << card << '\n';
        for (;;)
        {
            for (const auto& player : players)
                player->Show();
            Player& player = *players[turn];
            std::cout << player.GetName() << "の手番 ／ 場のチップ：" << pot << '\n';
            Action action = player.GetChips() == Config::NO_CHIPS ? Action::Take
                                                                  : player.ChooseAction(card, pot);
            if (action == Action::Take)
            {
                player.TakeCard(card, pot);
                std::cout << player.GetName() << "がカードとチップ" << pot << "枚を獲得。\n";
                break;
            }
            if (player.PayChip())
            {
                ++pot;
                std::cout << player.GetName() << "がチップを1枚支払いました。\n";
                turn = (turn + 1) % players.size();
            }
        }
        // 取ったプレイヤーが次のカードでも最初に選びます。
    }
    int best = players.front()->Score();
    for (const auto& player : players)
        best = std::min(best, player->Score());
    std::cout << "\n最終結果（小さい得点が勝ち）\n";
    for (const auto& player : players)
    {
        player->Show();
        std::cout << "カード点：" << player->CardPoints() << " 最終得点：" << player->Score();
        if (player->Score() == best)
            std::cout << " 勝者";
        std::cout << '\n';
    }
}
