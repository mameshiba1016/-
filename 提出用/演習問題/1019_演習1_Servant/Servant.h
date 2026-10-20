#pragma once

class Servant

{

public:
	virtual ~Servant() = default;

	//純粋仮想関数



	/// <summary>

	/// 攻撃処理

	/// </summary>

	virtual void Attack() = 0;



	/// <summary>

	/// プロフィール関数

	/// </summary>

	virtual void ShowProfile();

};

