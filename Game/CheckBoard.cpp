#include "CheckBoard.h"
#include "Utility/BoardDate.h"
#include "UnitMng.h"

CheckBoard::CheckBoard()
{
}

CheckBoard::~CheckBoard()
{
}

std::vector<Vector2> CheckBoard::GetPlayerAtackPos(void)
{
	return playerAtackPos_;
}

std::vector<Vector2> CheckBoard::GetEnemyAtackPos(void)
{
	return enemyAtackPos_;
}

bool CheckBoard::IsDeadLock(void)
{
	return false;
}

int CheckBoard::IsCheckMate(void)
{
	return 0;
}

void CheckBoard::CheckAtackPos(void)
{
	playerAtackPos_.clear();
	enemyAtackPos_.clear();
	std::vector<UNUB> units = UnitMng::GetPlayer();
	SetAtackPos(units,playerAtackPos_);
	units = UnitMng::GetEnemy();
	SetAtackPos(units,enemyAtackPos_);
}

void CheckBoard::SetAtackPos(std::vector<UNUB>& units, std::vector<Vector2>& atackpos)
{
	for (const auto& unit : units)
	{
		if ((unit->GetUnitID() >= Unit::wPawn1 && unit->GetUnitID() <= Unit::wPawn8) || (unit->GetUnitID() >= Unit::bPawn1 && unit->GetUnitID() <= Unit::bPawn8))
		{
			auto tmpPos = unit->GetMovableDestination();
			for (const auto& pos : tmpPos)
			{
				if (pos.x != unit->GetPos().x)
				{
					atackpos.emplace_back(pos);
				}
			}
		}
		else
		{
			auto tmpPos = unit->GetMovableDestination();
			for (const auto& pos : tmpPos)
			{
				atackpos.emplace_back(pos);
			}
		}
	}
}

