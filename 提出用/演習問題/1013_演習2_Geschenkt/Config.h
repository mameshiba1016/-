#pragma once

// この課題のルールと初期値。変更する場合はここでまとめて調整する。
namespace Config
{
    constexpr int INITIAL_CHIPS = 11;                   // 初期チップ枚数
    constexpr int MIN_CARD = 3;                         // カードの最小値
    constexpr int MAX_CARD = 35;                        // カードの最大値
    constexpr int CARD_COUNT = MAX_CARD - MIN_CARD + 1; // 用意するカードの総数
    constexpr int USED_CARD_COUNT = 24;                 // 使用するカード枚数
    constexpr int CPU_TAKE_THRESHOLD = 3;               // CPUが取得する得点増加の目安
    constexpr int CPU_LOW_CHIPS = 2;                    // CPUが取得を優先するチップ残数
    constexpr int NO_CHIPS = 0;                         // 支払えるチップがない状態
    constexpr const char* TAKE_INPUT = "1";             // カードを取る入力
    constexpr const char* PASS_INPUT = "2";             // チップを払う入力
} // namespace Config
