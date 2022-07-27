#pragma once
#include <array>
#include <vector>
#include "Unit.h"
#include "Vector2.h"

class BoardDate
{
	static std::array<std::array<Unit, 8>, 8> boardDate_;
public:
	static Unit GatDate(int& x, int& y);
	static std::array<std::array<Unit, 8>, 8> GetBoard();

	void SetDate(bool isPlayer, std::vector<int> date);
	void SetDate(std::array<std::array<Unit, 8>, 8> dat);
	void SetDate(Vector2 from, Vector2 to);

	BoardDate();
	~BoardDate();
};

