#pragma once
#include <array>
#include <vector>
#include "Unit.h"
#include "Vector2.h"

class BoardDate
{
	static std::array<std::array<Unit, 8>, 8> boardDate_;
public:
	/// <summary>
	/// 座補をもとにデータを取得
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <returns></returns>
	static Unit GatDate(int& x, int& y);
	/// <summary>
	/// ボード自体を取得
	/// </summary>
	/// <returns></returns>
	static std::array<std::array<Unit, 8>, 8> GetBoard();

	/// <summary>
	/// データ設定　陣営単位で初期化
	/// </summary>
	/// <param name="isPlayer"></param>
	/// <param name="date"></param>
	static void SetDate(bool isPlayer, std::vector<int> date);
	/// <summary>
	/// データ設定 ボード本体上書き
	/// </summary>
	/// <param name="dat"></param>
	static void SetDate(std::array<std::array<Unit, 8>, 8> dat);
	/// <summary>
	/// データ設定　ユニット移動用/移動元を移動先へ
	/// </summary>
	/// <param name="from"></param>
	/// <param name="to"></param>
	static void SetDate(Vector2 from, Vector2 to);

	void SetNewTarn(std::vector<std::pair<Unit, Vector2>>dat,bool isPlayer);


	BoardDate();
	~BoardDate();
private:
	static bool CheckKillUnit(Vector2 to);
	static void DelUnitDate(Unit id);
};

