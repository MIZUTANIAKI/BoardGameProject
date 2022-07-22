#pragma once
#include "Utility/BoardDate.h"
#include "Utility/BoardDateList.h"
#include "UnitBase.h"
#include "vector2.h"
#include <vector>
#include <memory>

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
};

