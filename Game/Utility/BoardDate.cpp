#include "BoardDate.h"
#include "UnitMng.h"

std::array<std::array<Unit, 8>, 8> BoardDate::boardDate_;

Unit BoardDate::GatDate(int& x, int& y)
{
	if (x >= 8)
		return Unit::non;
	if (y >= 8)
		return Unit::non;

	return boardDate_[y][x];
}

std::array<std::array<Unit, 8>, 8> BoardDate::GetBoard()
{
	return boardDate_;
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

void BoardDate::SetDate(std::array<std::array<Unit, 8>, 8> dat)
{
	boardDate_ = dat;
}

void BoardDate::SetDate(Vector2 from, Vector2 to)
{

	if (from.x >= 8 || to.x >= 8)
		return;
	if (from.y >= 8 || to.y >= 8)
		return;
	if (from.x < 0 || to.x < 0)
		return;
	if (from.y < 0 || to.y < 0)
		return;
	if (boardDate_[to.y][to.x] != Unit::non)
	{
		auto& unitlist = UnitMng::GetUnitList();
		for (const auto& unit : unitlist)
		{
			if (unit->GetUnitID() == boardDate_[to.y][to.x])
			{
				unit->KillUnit();
			}
		}
	}
	boardDate_[to.y][to.x] = boardDate_[from.y][from.x];
	boardDate_[from.y][from.x] = Unit::non;
	
}

BoardDate::BoardDate()
{
}

BoardDate::~BoardDate()
{
}
