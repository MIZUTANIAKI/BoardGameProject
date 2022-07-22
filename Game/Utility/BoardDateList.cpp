#include "BoardDateList.h"
#include "BoardDate.h"

std::list<std::array<std::array<Unit, 8>, 8>> BoardDateList::boardDateList_;

bool BoardDateList::CheckDate()
{
	static bool checkF = 0;
	static int count = 0;

	for (const auto& date : boardDateList_)
	{
		checkF = false;
		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 8; y++)
			{
				if (BoardDate::GatDate(x, y) != date[x][y])
				{
					checkF = false;
					break;
				}
			}
			if (!checkF)
			{
				break;
			}
		}
		if (checkF == true)
		{
			count++;
		}
		if (count >= 3)
		{
			return true;
		}
	}
	return false;
}

BoardDateList::BoardDateList()
{
	for (auto& date : boardDateList_)
	{
		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 8; y++)
			{
				date[y][x] = Unit::non;
			}
		}
	}
}

BoardDateList::~BoardDateList()
{
}
