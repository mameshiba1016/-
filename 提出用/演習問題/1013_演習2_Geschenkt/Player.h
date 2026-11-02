#pragma once
#include "Action.h"
#include "Config.h"
#include <string>
#include <vector>

// Playerのデータと公開する操作を宣言する。
class Player
{
private:
    std::string name;
    int chips = Config::INITIAL_CHIPS;
    std::vector<int> cards;

public:
    explicit Player(std::string name);
    virtual ~Player();
    // 名前を読み取り専用で取得する。
    const std::string& GetName() const;
    // 現在のチップ枚数を取得する。
    int GetChips() const;
    // 手札を読み取り専用で参照する。
    const std::vector<int>& GetCards() const;
    // チップがない場合は支払わず、失敗を呼び出し側へ返す。
    bool PayChip();
    // 獲得カードを昇順に保ち、カード上のチップも受け取る。
    void TakeCard(int card, int pot);
    // 連続するカードは先頭の最小値だけを加算する。
    int CardPoints() const;
    // カードの得点から手持ちチップを引く。小さい得点ほど有利。
    int Score() const;
    // 実際の手札を変えず、カードを取った場合の得点差を調べる。
    int AddedPoints(int card) const;
    // 行動を決定する。人間とCPUでは同じ関数名で異なる処理を行う。
    virtual Action ChooseAction(int card, int pot) = 0;
    // 手番の判断に使う名前、チップ、手札を表示する。
    void Show() const;
};
