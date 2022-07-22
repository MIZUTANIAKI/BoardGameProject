#include "BoardDate.h"

std::array<std::array<Unit, 8>, 8> BoardDate::boardDate_;

Unit BoardDate::GatDate(int& x, int& y)
{
	if (x >= 8)
		return Unit::non;
	if (y >= 8)
		return Unit::non;

	return boardDate_[y][x];
}

void BoardDate::SetDate(bool isPlayer, std::vector<int> date)
{
	int y = 0;
	int x = 0;
	if (isPlayer)
	{
		y = 6;
	}

	for (const auto& d : date)
	{
		boardDate_[y][x] = static_cast<Unit>(d);
		
		x++;
		if (x >= 8)
		{
			x = 0;
			y++;
		}
	}
}

BoardDate::BoardDate()
{
}

BoardDate::~BoardDate()
{
}
