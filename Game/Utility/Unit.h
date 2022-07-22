#pragma once

enum class Unit
{
	non,
	wPawn1,
	wPawn2,
	wPawn3,
	wPawn4,
	wPawn5,
	wPawn6,
	wPawn7,
	wPawn8,
	wKnight1,
	wKnight2,
	wBishop1,
	wBishop2,
	wRook1,
	wRook2,
	wQueen,
	wKing,
	bPawn1,
	bPawn2,
	bPawn3,
	bPawn4,
	bPawn5,
	bPawn6,
	bPawn7,
	bPawn8,
	bKnight1,
	bKnight2,
	bBishop1,
	bBishop2,
	bRook1,
	bRook2,
	bQueen,
	bKing
};

enum class UnitAnimation
{
	idle,
	move,
	del,
	atk
};

bool operator >(Unit u1, Unit u2);

bool operator <(Unit u1, Unit u2);

bool operator >=(Unit u1, Unit u2);

bool operator <=(Unit u1, Unit u2);

bool operator !=(Unit u1, Unit u2);

bool operator ==(Unit u1, Unit u2);

Unit operator +(Unit u1, Unit u2);

Unit operator -(Unit u1, Unit u2);

Unit operator ++(Unit u1);

Unit operator --(Unit u1);