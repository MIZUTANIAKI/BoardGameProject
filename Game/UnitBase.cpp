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
	return pos_;
}

void UnitBase::SetPos(Vector2& pos)
{
	pos_.Move(pos);
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

void UnitBase::PlayAnim(int num)
{
}
