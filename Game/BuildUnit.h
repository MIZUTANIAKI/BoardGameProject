#pragma once
#include "Utility/Unit.h"
#include "UnitBase.h"
class BuildUnit
{
public:
	BuildUnit();
	~BuildUnit();
	static UNUB Build(Unit id, Vector2& pos);
};

