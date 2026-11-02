#pragma once

// この課題のルールと初期値。変更する場合はここでまとめて調整する。
namespace Config
{
    constexpr int ENEMY_COUNT = 3;        // 登録する敵の数
    constexpr int MIN_HP = 30;            // 初期HPの下限
    constexpr int MAX_HP = 100;           // 初期HPの上限
    constexpr int MIN_DAMAGE = 20;        // ダメージの下限
    constexpr int MAX_DAMAGE = 90;        // ダメージの上限
    constexpr int DEFEATED_HP = 0;        // 削除対象になるHPの境界
    constexpr int FIRST_ENEMY_NUMBER = 1; // 入力する敵番号の開始値
} // namespace Config
