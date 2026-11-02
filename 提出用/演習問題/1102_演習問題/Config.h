#pragma once

// この課題のルールと初期値。変更する場合はここでまとめて調整する。
namespace Config
{
    constexpr int INITIAL_PLAYER_HP = 100;   // プレイヤーの初期HP
    constexpr int INITIAL_ENEMY_HP = 100;    // 敵の初期HP
    constexpr int PLAYER_ATTACK_DAMAGE = 30; // プレイヤーの攻撃力
    constexpr int ENEMY_ATTACK_DAMAGE = 20;  // 敵の通常攻撃力
    constexpr int DEFENDING_DAMAGE = 10;     // 防御時に受けるダメージ
    constexpr int HEAL_AMOUNT = 20;          // 回復量
    constexpr int DEFEATED_HP = 0;           // 戦闘不能になるHPの境界
} // namespace Config
