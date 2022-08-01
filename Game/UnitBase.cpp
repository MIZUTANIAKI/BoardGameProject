#include "UnitBase.h"

UnitBase::UnitBase()
{
	unitID_ = Unit::non;
	hp_ = 1;
	attack_ = 1;
	animID_ = UnitAnimation::idle;
	lock_ = false;
}

UnitBase::UnitBase(Unit id)
{
	unitID_ = id;
	hp_ = 1;
	attack_ = 1;
	animID_ = UnitAnimation::idle;
	lock_ = false;
}

UnitBase::~UnitBase()
{
}

void UnitBase::Update()
{
}

void UnitBase::Draw(void)
{
}

Unit UnitBase::GetUnitID(void)
{
	return unitID_;
}

int UnitBase::GetHP(void)
{
	return hp_;
}

Vector2 UnitBase::GetPos()
{
	return pos_ / 60;
}

void UnitBase::SetPos(Vector2& pos)
{
	pos_ = std::move(pos *= 60);
}

void UnitBase::SetLock(bool isLock)
{
	lock_ = isLock;
}

bool UnitBase::GetLock(void)
{
	return lock_;
}

std::vector<Vector2> UnitBase::GetMovableDestination(void)
{
	return std::vector<Vector2>();
}

void UnitBase::KillUnit(void)
{
	hp_ = 0;
	lock_ = true;
	PlayAnim((int)UnitAnimation::del);
}

void UnitBase::PlayAnim(int num)
{
	animID_ = static_cast<UnitAnimation>(num);
}

bool UnitBase::IsKillUnit(void)
{
	if (hp_ <= 0)
	{
		return true;
	}
	return false;
}
