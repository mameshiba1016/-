#pragma once

// 敵の更新と描画を表す。デストラクタの出力で破棄のタイミングを確認できる。
class Enemy
{
public:
    ~Enemy();
    void Update();
    void Draw() const;
};
