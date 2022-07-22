#include "BuildUnit.h"

BuildUnit::BuildUnit()
{
}

BuildUnit::~BuildUnit()
{
}

UNUB BuildUnit::Build(Unit id)
{
	return UNUB();
	switch (id)
	{
	case Unit::non:
		return UNUB();
		break;
	case Unit::wPawn1:
		break;
	case Unit::wPawn2:
		break;
	case Unit::wPawn3:
		break;
	case Unit::wPawn4:
		break;
	case Unit::wPawn5:
		break;
	case Unit::wPawn6:
		break;
	case Unit::wPawn7:
		break;
	case Unit::wPawn8:
		break;
	case Unit::wKnight1:
		break;
	case Unit::wKnight2:
		break;
	case Unit::wBishop1:
		break;
	case Unit::wBishop2:
		break;
	case Unit::wRook1:
		break;
	case Unit::wRook2:
		break;
	case Unit::wQueen:
		break;
	case Unit::wKing:
		break;
	case Unit::bPawn1:
		break;
	case Unit::bPawn2:
		break;
	case Unit::bPawn3:
		break;
	case Unit::bPawn4:
		break;
	case Unit::bPawn5:
		break;
	case Unit::bPawn6:
		break;
	case Unit::bPawn7:
		break;
	case Unit::bPawn8:
		break;
	case Unit::bKnight1:
		break;
	case Unit::bKnight2:
		break;
	case Unit::bBishop1:
		break;
	case Unit::bBishop2:
		break;
	case Unit::bRook1:
		break;
	case Unit::bRook2:
		break;
	case Unit::bKing:
		break;
	default:
		break;
	}
}
