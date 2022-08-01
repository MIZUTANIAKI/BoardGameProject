#pragma once
#include "HandBase.h"
#include "Vector2.h"
#include <Vector>
#include "Utility/Unit.h"

class Player2Hand :
    public HandBase
{
public:
	Player2Hand();
	virtual ~Player2Hand();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <returns>true＝移動先決定</returns>
	bool Update() override;

	/// <summary>
	///	ターゲットを解除（リセット）
	/// </summary>
	void OutOfTarget();

	void Draw() override;

	/// <summary>
	/// Updateがtrueだった時に使用。
	/// 動かす駒とその移動先を提示
	/// </summary>
	/// <returns>UnitID、移動先</returns>
	std::pair<Unit, Vector2> NextMove() override;
private:
	bool lockTarget_;
	Unit lockUnit_;
	std::vector<Vector2> movePosList_;

	/// <summary>
	/// targetを決めてマウスを左クリックした。
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool CheckMove(void);
	/// <summary>
	/// まだtargetを決めてないときにマウスを左クリックした。
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool CheckTaget(void);
};

