#include "HandBase.h"

HandBase::HandBase()
{
	handID_ = HandName::Non;
	for (int i = 0; i < 64; i++)
	{
		date_[i / 8][i % 8] = Unit::non;
	}
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

void HandBase::SetDate(std::array<std::array<Unit, 8>, 8> date)
{
	date_ = date;
}

HandName HandBase::GetHandID(void)
{
	return handID_;
}
