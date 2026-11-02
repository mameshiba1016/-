// 1024_演習問題 / Map.cpp
// 処理の流れと各操作の意図をコメントで示す。
#include "Map.h"
#include "Dxlib.h"
#include <fstream>
#include <sstream>
#include <string>

// 画像ハンドルを未使用の-1にして、読み込み前の状態をそろえる。
Map::Map() : mapXNum(0), mapYNum(0), isInitialized(false)
{
    for (int i = 0; i < Config::MAP_CHIP_IMAGE_COUNT; i++)
    {
        chipImages[i] = Config::INVALID_IMAGE_HANDLE;
    }
}

// オブジェクトの破棄時に、画像などの解放処理を呼び出す。
Map::~Map()
{
    Finalize();
}
