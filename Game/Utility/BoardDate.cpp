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
	bool delFlag = false;
	CheckKillUnit(to);
	if ((boardDate_[from.y][from.x] <= Unit::wPawn8 && from.y == 6))
	{
		if (from.y - to.y >= 2)
		{
			if (CheckKillUnit(Vector2(from.x, from.y - 1)))
				delFlag = true;
			boardDate_[from.y - 1][from.x] = boardDate_[from.y][from.x];
		}
	}
	else if (boardDate_[from.y][from.x] >= Unit::wPawn1 && boardDate_[from.y][from.x] <= Unit::bPawn8 && from.y == 1)
	{
		if (to.y - from.y >= 2)
		{
			if (CheckKillUnit(Vector2(from.x, from.y + 1)))
				delFlag = true;
			boardDate_[from.y + 1][from.x] = boardDate_[from.y][from.x];
		}
	}

	if (delFlag)
	{
		DelUnitDate(boardDate_[to.y][to.x]);
	}
	boardDate_[to.y][to.x] = boardDate_[from.y][from.x];
	boardDate_[from.y][from.x] = Unit::non;
}

void BoardDate::SetNewTarn(std::vector<std::pair<Unit, Vector2>> dat, bool isPlayer)
{
	if (isPlayer)
	{
		for (Unit i = Unit::wPawn1; i <= Unit::wKing; i = i + 1)
		{
			DelUnitDate(i);
		}
	}
	else
	{
		for (Unit i = Unit::bPawn1; i >= Unit::wKing; i = i + 1)
		{
			DelUnitDate(i);
		}
	}
	for (const auto& d : dat)
	{
		if (d.second.x >= 0 && d.second.x < 8 && d.second.y >= 0 && d.second.y < 8)
		{
			boardDate_[d.second.y][d.second.x] = d.first;
		}
	}
}

bool BoardDate::CheckKillUnit(Vector2 to)
{
	if (boardDate_[to.y][to.x] != Unit::non)
	{
		auto& unitlist = UnitMng::GetUnitList();
		for (const auto& unit : unitlist)
		{
			if (unit->GetUnitID() == boardDate_[to.y][to.x])
			{
				unit->KillUnit();
				return true;
			}
		}
		return true;
	}
	return false;
}

void BoardDate::DelUnitDate(Unit id)
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (boardDate_[y][x] == id)
			{
				boardDate_[y][x] = Unit::non;
			}
		}
	}

}

BoardDate::BoardDate()
{
}

BoardDate::~BoardDate()
{
}
