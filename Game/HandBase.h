#pragma once
#include <array>
#include <vector>
#include <utility>
#include "Utility/Unit.h"
#include "Vector2.h"

enum class HandName
{
	Non,
	Player,
	Enemy,
};

class HandBase
{
public:
	HandBase();
	virtual ~HandBase();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <returns>true＝移動先決定</returns>
	virtual bool Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// Updateがtrueだった時に使用。
	/// 動かす駒とその移動先を提示
	/// </summary>
	/// <returns>UnitID、移動先</returns>
	virtual std::pair<Unit, Vector2> NextMove();

	/// <summary>
	/// 手種別取得
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	HandName GetHandID(void);
private:

protected:
	/// <summary>
	/// ID　種類
	/// </summary>
	HandName handID_;
	std::pair<Unit, Vector2> nextPos_;
};

