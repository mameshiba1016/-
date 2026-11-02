#include "Config.h"
#include "VectorDemo.h"
// 1024_演習問題 / Sample.cpp
// 処理の流れと各操作の意図をコメントで示す。
#include <iostream>
#include <vector>

// class Enemy
//{
// public:
//	Enemy();
//	~Enemy();
//
// private:
//
// };
// オブジェクトの準備と処理の呼び出しを行う、プログラムの入口。
int RunVectorDemo()
{
    // Enemy enemy;
    // ベクターを宣言
    std::vector<int> number;
    std::vector<float> number2;
    // std::vector<Enemy> enemies;
    // 追加
    number.push_back(Config::SAMPLE_FIRST_VALUE);
    number.push_back(Config::SAMPLE_SECOND_VALUE);
    number.push_back(Config::SAMPLE_THIRD_VALUE);
    // 要素数確認
    std::cout << number.size() << std::endl;
    //
    int num = number[0];
    std::cout << num;
    // 削除
    number.clear();
    return 0;
}
