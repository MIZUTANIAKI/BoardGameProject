#pragma once
#include <array>
#include <list>
#include "Unit.h"

class BoardDateList
{
	static std::list<std::array<std::array<Unit, 8>, 8>> boardDateList_;
public:
	static bool CheckDate();
	static void SetDate(std::array<std::array<Unit, 8>, 8> dat);

	BoardDateList();
	~BoardDateList();
};

