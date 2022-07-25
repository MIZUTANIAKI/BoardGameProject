#include "HandBase.h"

HandBase::HandBase()
{
	handID_ = HandName::Non;
}

HandBase::~HandBase()
{
}

bool HandBase::Update()
{
	return false;
}

void HandBase::Draw()
{
}

std::pair<Unit, Vector2> HandBase::NextMove()
{
	return std::pair<Unit, Vector2>();
}

HandName HandBase::GetHandID(void)
{
	return handID_;
}
