#include "UnitMng.h"

std::map<bool, std::vector<UNUB>> UnitMng::unitList_;

UnitMng::UnitMng()
{
	Reset();
}

UnitMng::~UnitMng()
{
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
	std::vector<UNUB> tmpVec;
	for (const auto& dat : unitList_)
	{
		tmpVec.emplace_back(dat.second);
	}
	return tmpVec;
	// TODO: return ステートメントをここに挿入します
}

void UnitMng::SetPlayer(std::vector<UNUB> vec)
{
	unitList_.try_emplace(true, std::move(vec));
}

void UnitMng::SetEnemy(std::vector<UNUB> vec)
{
	unitList_.try_emplace(false, std::move(vec));
}
