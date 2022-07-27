#include "Board.h"
#include "ReadMng.h"
#include <DxLib.h>
#include "UnitMng.h"
#include "PlayerHand.h"


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
	isPlayerTurnF_ = true;
	handForPlayer_ = std::make_unique<PlayerHand>();
	handForEnemy_ = std::make_unique<HandBase>();
}

Board::~Board()
{
}

void Board::Update()
{
	if (isPlayerTurnF_)
	{
		if (handForPlayer_->Update())
		{
			return;
		}
		auto tmpMoveUnitDate = handForPlayer_->NextMove();
		Move(tmpMoveUnitDate.first, tmpMoveUnitDate.second);
	}
	else
	{
		if (handForEnemy_->Update())
		{
			return;
		}
		auto tmpMoveUnitDate = handForEnemy_->NextMove();
		Move(tmpMoveUnitDate.first, tmpMoveUnitDate.second);
	}
}

void Board::Move(Unit id, Vector2 pos)
{
	if (id >= Unit::bPawn1)
	{
		for (const auto& el : UnitMng::GetEnemy())
		{
			if (el->GetUnitID() == id)
			{
				boardDate_->SetDate(el->GetPos(), pos);
				el->SetPos(pos);
			}
		}
	}
	else
	{
		for (const auto& pl : UnitMng::GetPlayer())
		{
			if (pl->GetUnitID() == id)
			{
				boardDate_->SetDate(pl->GetPos(), pos);
				pl->SetPos(pos);
			}
		}
	}
}
