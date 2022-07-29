#pragma once
#include "Utility/Unit.h"
#include <memory>
#include <vector>
#include "Vector2.h"
#include <DxLib.h>

class UnitBase;
using UNUB = std::shared_ptr<UnitBase>;
class UnitBase
{
public:
	UnitBase();
	UnitBase(Unit id);
	virtual ~UnitBase();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param></param>
	/// <returns></returns>
	virtual void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name=""></param>
	virtual void Draw(void);

	/// <summary>
	/// ユニット種別取得
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Unit GetUnitID(void);

	/// <summary>
	///	HP取得
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	int GetHP(void);

	Vector2 GetPos();

	void SetPos(Vector2& pos);

	/// <summary>
	/// ロックを掛ける・はずす
	/// </summary>
	/// <param name="isLock">true=Lock/false=UnLock</param>
	void SetLock(bool isLock);
	/// <summary>
	/// ロックの状態を取得
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool GetLock(void);

	/// <summary>
	/// 移動可能先を取得
	/// </summary>
	/// <param name=""></param>
	/// <returns>移動可能先のリスト　からの場合は無し</returns>
	virtual std::vector<Vector2> GetMovableDestination(void);

	void KillUnit(void);
private:
	/// <summary>
	/// アニメーション再生
	/// </summary>
	/// <param name="num"></param>
	void PlayAnim(int num);

protected:
	/// <summary>
	/// ID　種類
	/// </summary>
	Unit unitID_;
	/// <summary>
	/// ヒットポイント
	/// </summary>
	int hp_;
	/// <summary>
	/// 攻撃力
	/// </summary>
	int attack_;
	/// <summary>
	/// アニメーションID
	/// </summary>
	UnitAnimation animID_;
	/// <summary>
	/// 座標
	/// </summary>
	Vector2 pos_;
	/// <summary>
	/// ロック　移動が可能かどうか
	/// </summary>
	bool lock_;

	bool IsKillUnit(void);
};

