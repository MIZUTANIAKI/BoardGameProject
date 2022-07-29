#include "UnitMng.h"

std::map<bool, std::vector<UNUB>> UnitMng::unitList_;
std::vector<UNUB> UnitMng::allVector_;

UnitMng::UnitMng()
{
	Reset();
}

UnitMng::~UnitMng()
{
}

void UnitMng::Update(void)
{
	for (const auto& dat : unitList_)
	{
		for (const auto& uni : dat.second)
		{
			uni->Update();
		}
	}
}

void UnitMng::Reset(void)
{
	unitList_.clear();
}

std::vector<UNUB>& UnitMng::GetPlayer(void)
{
	return unitList_[true];
}

std::vector<UNUB>& UnitMng::GetEnemy(void)
{
	return unitList_[false];
}

std::vector<UNUB>& UnitMng::GetUnitList(void)
{
	
	allVector_.clear();
	for (const auto& dat : unitList_)
	{
		for (const auto& uni : dat.second)
		{
			allVector_.emplace_back(uni);
		}
	}
	return allVector_;
}

void UnitMng::SetPlayer(std::vector<UNUB> vec)
{
	unitList_.try_emplace(true, std::move(vec));
}

void UnitMng::SetEnemy(std::vector<UNUB> vec)
{
	unitList_.try_emplace(false, std::move(vec));
}
