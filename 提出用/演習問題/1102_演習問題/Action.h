#pragma once
#include "Config.h"
// 1102_演習問題 / Action.h
// 宣言とクラスの役割をまとめる。
// 行動を名前で表し、数値だけの指定による取り違えを防ぐ。
enum class Action
{
    Attack = 1,
    Defend = 2,
    Heal = 3
};
