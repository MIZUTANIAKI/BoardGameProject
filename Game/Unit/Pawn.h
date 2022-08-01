#pragma once
#include "UnitBase.h"
class Pawn :
    public UnitBase
{
public:
	Pawn(Unit id);
	~Pawn();

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
	void MoveQueen(Vector2& pos, std::array<std::array<Unit, 8Ui64>, 8Ui64>& date, std::vector<Vector2>& movePos);
	void MovePawn(Vector2& pos, std::array<std::array<Unit, 8Ui64>, 8Ui64>& date, std::vector<Vector2>& movePos);

private:
	int moveMode_;	//移動モード
};

