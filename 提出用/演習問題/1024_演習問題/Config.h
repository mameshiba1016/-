#pragma once

// 1024_演習問題 / Config.h
// 宣言とクラスの役割をまとめる。
// ゲームの設定値まとめるファイル
// 数値やファイルパスを変更するときは、ここを確認します。
namespace Config
{
    // マップチップ画像の設定
    constexpr int MAP_CHIP_SIZE = 64;
    constexpr int MAP_CHIP_IMAGE_COLUMNS = 16;
    constexpr int MAP_CHIP_IMAGE_ROWS = 4;
    constexpr int MAP_CHIP_IMAGE_COUNT = MAP_CHIP_IMAGE_COLUMNS * MAP_CHIP_IMAGE_ROWS;
    // マップの描画開始位置
    constexpr int MAP_DRAW_ORIGIN_X = 0;
    constexpr int MAP_DRAW_ORIGIN_Y = 0;
    // CSVの値
    constexpr int MAP_EMPTY = 0;
    // マップファイル
    constexpr char MAP_CHIP_IMAGE_PATH[] = "data/island.png";
    constexpr char MAP_HIT_CSV_PATH[] = "data/island_hit.csv";
    constexpr char MAP_BACK_CSV_PATH[] = "data/island_back.csv";
    constexpr char MAP_BASE_CSV_PATH[] = "data/island_base.csv";
    constexpr char MAP_NEAR_CSV_PATH[] = "data/island_near.csv";
    constexpr int SAMPLE_FIRST_VALUE = 10; // vectorに登録する練習用の値
    constexpr int SAMPLE_SECOND_VALUE = 20;
    constexpr int SAMPLE_THIRD_VALUE = 30;
    constexpr int INVALID_IMAGE_HANDLE = -1; // 画像が未読込の状態
} // namespace Config
