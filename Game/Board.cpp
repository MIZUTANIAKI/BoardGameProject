#include "Board.h"
#include "ReadMng.h"
#include <DxLib.h>
#include "UnitMng.h"
#include "PlayerHand.h"
#include "BuildUnit.h"

Board::Board()
{
	boardDate_ = std::make_unique<BoardDate>();
	boardDateList_ = std::make_unique<BoardDateList>();

	std::unique_ptr<ReadMng> filedat;
	std::vector<UNUB> playerunitList_;
	std::vector<UNUB> enemyunitList_;
	filedat = std::make_unique<ReadMng>("./Resource/enemyDef.txt");
	auto dat = std::move(filedat->GetDate());
	boardDate_->SetDate(false, dat);
	int num = 0;
	Vector2 tmpPos;
	for (const auto& d : dat)
	{
		Unit tmpUnit = static_cast<Unit>(d);
		if (tmpUnit != Unit::non)
		{
			tmpPos.x = num % 8;
			tmpPos.y = num / 8;
			enemyunitList_.emplace_back(std::move(BuildUnit::Build(tmpUnit, tmpPos)));
		}
		num++;
	}
	filedat = std::make_unique<ReadMng>("./Resource/playerDef.txt");
	dat = std::move(filedat->GetDate());
	boardDate_->SetDate(true, dat);
	num += 8 * 4;
	for (const auto& d : dat)
	{
		Unit tmpUnit = static_cast<Unit>(d);
		if (tmpUnit != Unit::non)
		{
			tmpPos.x = num % 8;
			tmpPos.y = num / 8;
			playerunitList_.emplace_back(std::move(BuildUnit::Build(tmpUnit, tmpPos)));
		}
		num++;
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
	UnitMng::Update();
	if (isPlayerTurnF_)
	{
		if (!handForPlayer_->Update())
		{
			return;
		}
		auto tmpMoveUnitDate = handForPlayer_->NextMove();
		Move(tmpMoveUnitDate.first, tmpMoveUnitDate.second);
	}
	else
	{
		if (!handForEnemy_->Update())
		{
			return;
		}
		auto tmpMoveUnitDate = handForEnemy_->NextMove();
		Move(tmpMoveUnitDate.first, tmpMoveUnitDate.second);
	}
}

void Board::Draw()
{
	auto& unitList = UnitMng::GetUnitList();
	for (const auto& Unit : unitList)
	{
		Unit->Draw();
	}
	if (isPlayerTurnF_)
	{
		handForPlayer_->Draw();
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
