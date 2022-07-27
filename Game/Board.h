#pragma once
#include "Utility/BoardDate.h"
#include "Utility/BoardDateList.h"
#include "UnitBase.h"
#include "vector2.h"
#include <vector>
#include <memory>
#include "HandBase.h"

class Board
{
public:
	Board();
	~Board();

	void Update();
private:
	void Move(Unit id, Vector2 pos);
	std::unique_ptr<BoardDate> boardDate_;
	std::unique_ptr<BoardDateList> boardDateList_;
	std::unique_ptr<HandBase> handForPlayer_;
	std::unique_ptr<HandBase> handForEnemy_;
	bool isPlayerTurnF_;
};

