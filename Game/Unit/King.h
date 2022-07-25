#pragma once
#include "UnitBase.h"
class King :
	public UnitBase
{
public:
	King(Unit id) :UnitBase(id) {};
	~King();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param></param>
	/// <returns></returns>
	void Update() override;

	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name=""></param>
	void Draw(void) override;

	/// <summary>
	/// 移動可能先を取得
	/// </summary>
	/// <param name=""></param>
	/// <returns>移動可能先のリスト　からの場合は無し</returns>
	std::vector<Vector2> GetMovableDestination(void) override;
};

