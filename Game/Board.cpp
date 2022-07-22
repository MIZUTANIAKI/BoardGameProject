#include "Board.h"
#include "ReadMng.h"
#include <DxLib.h>
#include "UnitMng.h"


Board::Board()
{
	boardDate_ = std::make_unique<BoardDate>();
	boardDateList_ = std::make_unique<BoardDateList>();

	std::unique_ptr<ReadMng> filedat1;
	filedat1 = std::make_unique<ReadMng>("./Resource/playerDef.txt");
	auto dat = std::move(filedat1->GetDate());
	boardDate_->SetDate(true, dat);

	std::vector<UNUB> playerunitList_;
	std::vector<UNUB> enemyunitList_;
	for (const auto& d : dat)
	{
		Unit tmpUnit = static_cast<Unit>(d);
		if (tmpUnit != Unit::non)
		{
			playerunitList_.emplace_back(std::make_unique<UnitBase>(tmpUnit));
		}
	}
	UnitMng::Reset();
	UnitMng::SetPlayer(std::move(playerunitList_));
	UnitMng::SetEnemy(std::move(enemyunitList_));
}

Board::~Board()
{
}

void Board::Update()
{
}

void Board::Move(Unit id, Vector2 pos)
{
	if (id >= Unit::bPawn1)
	{
		for (const auto& el : enemyunitList_)
		{
			if (el->GetUnitID() == id)
			{
				el->SetPos(pos);
			}
		}
	}
	else
	{
		for (const auto& pl : playerunitList_)
		{
			if (pl->GetUnitID() == id)
			{
				pl->SetPos(pos);
			}
		}
	}
}
