#include "Unit.h"

bool operator>(Unit u1, Unit u2)
{
	return (static_cast<int>(u1) > static_cast<int>(u2));
}

bool operator<(Unit u1, Unit u2)
{
	return (static_cast<int>(u1) < static_cast<int>(u2));
}

bool operator>=(Unit u1, Unit u2)
{
	return (static_cast<int>(u1) >= static_cast<int>(u2));
}

bool operator<=(Unit u1, Unit u2)
{
	return (static_cast<int>(u1) <= static_cast<int>(u2));
}

bool operator!=(Unit u1, Unit u2)
{
	return (static_cast<int>(u1) != static_cast<int>(u2));
}

bool operator==(Unit u1, Unit u2)
{
	return (static_cast<int>(u1) == static_cast<int>(u2));
}

Unit operator+(Unit u1, Unit u2)
{
	int rtnnum = static_cast<int>(u1) + static_cast<int>(u2);
	if (rtnnum > static_cast<int>(Unit::bKing))
	{
		rtnnum -= static_cast<int>(Unit::bKing);
	}
	return static_cast<Unit>(rtnnum);
}

Unit operator-(Unit u1, Unit u2)
{
	int rtnnum = static_cast<int>(u1) - static_cast<int>(u2);
	if (rtnnum < 0)
	{
		rtnnum = static_cast<int>(Unit::bKing) - rtnnum;
	}
	return static_cast<Unit>(rtnnum);
}

Unit operator++(Unit u1)
{
	int rtnnum = static_cast<int>(u1);
	rtnnum++;
	if (rtnnum > static_cast<int>(Unit::bKing))
	{
		return Unit::non;
	}
	return static_cast<Unit>(rtnnum);
}

Unit operator--(Unit u1)
{
	int rtnnum = static_cast<int>(u1);
	rtnnum--;
	if (rtnnum < 0)
	{
		return Unit::bKing;
	}
	return static_cast<Unit>(rtnnum);
}
