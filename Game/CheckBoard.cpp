#include "CheckBoard.h"
#include "Utility/BoardDate.h"
#include "UnitMng.h"

std::vector<Vector2> CheckBoard::playerAtackPos_;
std::vector<Vector2> CheckBoard::enemyAtackPos_;
bool CheckBoard::checkPlayerKing_;
bool CheckBoard::checkEnemyKing_;

CheckBoard::CheckBoard()
{
    playerAtackPos_.clear();
    enemyAtackPos_.clear();
    checkPlayerKing_ = false;
    checkEnemyKing_ = false;
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

int CheckBoard::KingCheckNow(bool isPlayer)
{
    if (isPlayer)
    {
        return checkPlayerKing_;
    }

    return checkEnemyKing_;
}

void CheckBoard::SetCheckKing(bool now, bool isPlayer)
{
    if (isPlayer)
    {
        checkPlayerKing_ = now;
        return;
    }

    checkEnemyKing_ = now;

}

void CheckBoard::SetAtackPos(std::vector<UNUB>& units, std::vector<Vector2>& atackpos)
{
	for (const auto& unit : units)
	{
		if ((unit->GetUnitID() >= Unit::wPawn1 && unit->GetUnitID() <= Unit::wPawn8) || (unit->GetUnitID() >= Unit::bPawn1 && unit->GetUnitID() <= Unit::bPawn8))
		{
			auto pos = unit->GetPos();
            CheckPawn(pos, unit, atackpos);
		}
        else if (unit->GetUnitID() == Unit::wKing)
        {
            auto pos = unit->GetPos();
            CheckKing(pos, atackpos);
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

void CheckBoard::CheckPawn(Vector2& pos, const UNUB& unit, std::vector<Vector2>& atackpos)
{
    if (pos.y - 1 >= 0 && (unit->GetUnitID() >= Unit::wPawn1 && unit->GetUnitID() <= Unit::wPawn8))
    {
        if (pos.x - 1 >= 0)
        {
            atackpos.emplace_back(pos.x - 1, pos.y - 1);
        }
        if (pos.x + 1 < 8)
        {
            atackpos.emplace_back(pos.x + 1, pos.y - 1);
        }
    }
    if (pos.y + 1 < 8 && (unit->GetUnitID() >= Unit::bPawn1 && unit->GetUnitID() <= Unit::bPawn8))
    {
        atackpos.emplace_back(pos.x - 1, pos.y + 1);
        atackpos.emplace_back(pos.x + 1, pos.y + 1);
    }
}

void CheckBoard::CheckKing(Vector2& pos, std::vector<Vector2>& atackpos)
{
    //ã
    if (pos.y - 1 >= 0)
    {
        //¶
        if (pos.x - 1 >= 0)
        {
            atackpos.emplace_back(pos.x - 1, pos.y - 1);
        }
        //’†‰›
        atackpos.emplace_back(pos.x, pos.y - 1);
        //‰E
        if (pos.x + 1 < 8)
        {
            atackpos.emplace_back(pos.x + 1, pos.y - 1);
        }
    }
    //’†
    //¶
    if (pos.x - 1 >= 0)
    {
        atackpos.emplace_back(pos.x - 1, pos.y);
    }
    //‰E
    if (pos.x + 1 < 8)
    {
        atackpos.emplace_back(pos.x + 1, pos.y);
    }
    //‰º
    if (pos.y + 1 < 8)
    {
        //¶
        if (pos.x - 1 >= 0)
        {
            atackpos.emplace_back(pos.x - 1, pos.y + 1);
        }
        //’†‰›
        atackpos.emplace_back(pos.x, pos.y + 1);
        //‰E
        if (pos.x + 1 < 8)
        {
            atackpos.emplace_back(pos.x + 1, pos.y + 1);
        }
    }
}

