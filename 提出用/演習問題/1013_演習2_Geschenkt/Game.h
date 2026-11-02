#pragma once
#include "Player.h"
#include <memory>
#include <vector>

// Gameのデータと公開する操作を宣言する。
class Game
{
private:
    std::vector<std::unique_ptr<Player>> players;
    std::vector<int> deck;

public:
    // 3人分のプレイヤーを用意し、3～35のカードを混ぜて24枚を使う。
    void Initialize();
    // カードを1枚ずつ公開し、最後のカードが取られるまで手番を進める。
    void Run();
};
