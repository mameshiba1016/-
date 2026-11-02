#include <iostream>
#include <utility>
#include <algorithm>
#include "Config.h"
#include "Player.h"

// Playerの操作を実装する。
Player::Player(std::string name) : name(std::move(name))
{
}

// Playerの操作を実装する。
const std::string& Player::GetName() const
{
    return name;
}

// Playerの操作を実装する。
int Player::GetChips() const
{
    return chips;
}

// Playerの操作を実装する。
const std::vector<int>& Player::GetCards() const
{
    return cards;
}

// Playerの操作を実装する。
bool Player::PayChip()
{
    if (chips == Config::NO_CHIPS)
        return false;
    --chips;
    return true;
}

// Playerの操作を実装する。
void Player::TakeCard(int card, int pot)
{
    cards.push_back(card);
    std::sort(cards.begin(), cards.end());
    chips += pot;
}

// Playerの操作を実装する。
int Player::CardPoints() const
{
    // 連番の途中は加算せず、各グループの最小値だけを得点にする。
    int sum = 0, previous = Config::MIN_CARD - 1;
    for (int card : cards)
    {
        if (card != previous + 1)
            sum += card;
        previous = card;
    }
    return sum;
}

// Playerの操作を実装する。
int Player::Score() const
{
    return CardPoints() - chips;
}

// Playerの操作を実装する。
int Player::AddedPoints(int card) const
{
    auto values = cards;
    values.push_back(card);
    std::sort(values.begin(), values.end());
    // 連番の途中は加算せず、各グループの最小値だけを得点にする。
    int sum = 0, previous = Config::MIN_CARD - 1;
    for (int value : values)
    {
        if (value != previous + 1)
            sum += value;
        previous = value;
    }
    return sum - CardPoints();
}

// Playerの操作を実装する。
void Player::Show() const
{
    std::cout << name << " チップ：" << chips << " カード：";
    for (int card : cards)
        std::cout << card << ' ';
    std::cout << '\n';
}

// 基底クラス経由でも安全に破棄できるよう、仮想デストラクタを実装する。
Player::~Player() = default;
