#include "BuildUnit.h"
#include "Unit/Pawn.h"
#include "Unit/Knight.h"
#include "Unit/Rook.h"
#include "Unit/Bishop.h"
#include "Unit/Queen.h"
#include "Unit/King.h"


BuildUnit::BuildUnit()
{
}

BuildUnit::~BuildUnit()
{
}

UNUB BuildUnit::Build(Unit id, Vector2& pos)
{
	if (id <= Unit::non || id > Unit::bKing)
	{
		return UNUB();
	}
	if ((id >= Unit::wPawn1 && id <= Unit::wPawn8) || ((id >= Unit::bPawn1 && id <= Unit::bPawn8)))
	{
		auto unit = std::make_shared<Pawn>(id);
		unit->SetPos(pos);
		return std::move(unit);
	}
	if (id == Unit::wKnight1 || id == Unit::wKnight2 || id == Unit::bKnight1 || id == Unit::bKnight2)
	{
		auto unit = std::make_shared<Knight>(id);
		unit->SetPos(pos);
		return std::move(unit);
	}
	if (id == Unit::wRook1 || id == Unit::wRook2 || id == Unit::bRook1 || id == Unit::bRook2)
	{
		auto unit = std::make_shared<Rook>(id);
		unit->SetPos(pos);
		return std::move(unit);
	}
	if (id == Unit::wBishop1 || id == Unit::wBishop2 || id == Unit::bBishop1 || id == Unit::bBishop2)
	{
		auto unit = std::make_shared<Bishop>(id);
		unit->SetPos(pos);
		return std::move(unit);
	}
	if (id == Unit::wQueen || id == Unit::bQueen)
	{
		auto unit = std::make_shared<Queen>(id);
		unit->SetPos(pos);
		return std::move(unit);
	}
	if (id == Unit::wKing || id == Unit::bKing)
	{
		auto unit = std::make_shared<King>(id);
		unit->SetPos(pos);
		return std::move(unit);
	}
	return UNUB();
}

