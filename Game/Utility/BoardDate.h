#pragma once
#include <array>
#include <vector>
#include "Unit.h"

class BoardDate
{
	static std::array<std::array<Unit, 8>, 8> boardDate_;
public:
	static Unit GatDate(int& x, int& y);
	static std::array<std::array<Unit, 8>, 8> GetBoard();

	void SetDate(bool isPlayer, std::vector<int> date);

	BoardDate();
	~BoardDate();
};

