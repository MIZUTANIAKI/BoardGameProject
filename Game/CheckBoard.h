#pragma once
#include <vector>
#include "Vector2.h"

class CheckBoard
{
	std::vector<Vector2> playerAtackPos_;
	std::vector<Vector2> enemyAtackPos_;
public:
	CheckBoard();
	~CheckBoard();
	/// <summary>
	/// プレイヤーが攻撃中のマスを取得
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	std::vector<Vector2> GetPlayerAtackPos(void);
	/// <summary>
	/// 敵が攻撃中のマスを取得
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	std::vector<Vector2> GetEnemyAtackPos(void);

	/// <summary>
	/// 盤面がロックされている状態かどうか
	/// trueならステイルメイトで引き分け
	/// </summary>
	/// <param name=""></param>
	/// <returns>true=ロック</returns>
	bool IsDeadLock(void);

	/// <summary>
	/// チェックメイトしているか
	/// </summary>
	/// <param name=""></param>
	/// <returns>0=否 1=プレイヤー 2=敵</returns>
	int IsCheckMate(void);

	/// <summary>
	/// 攻撃情報の更新
	/// </summary>
	/// <param name=""></param>
	void CheckAtackPos(void);
	void SetAtackPos(std::vector<UNUB>& units, std::vector<Vector2>& atackpos);
private:
};

