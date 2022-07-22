#pragma once
#include "UnitBase.h"
#include <vector>
#include <map>

class UnitMng
{
	static std::map<bool, std::vector<UNUB>> unitList_;
public:
	UnitMng();
	~UnitMng();
	static void Update(void);
	static void Reset(void);
	static std::vector<UNUB>& GetPlayer(void);
	static std::vector<UNUB>& GetEnemy(void);
	static std::vector<UNUB>& GetUnitList(void);
	static void SetPlayer(std::vector<UNUB> vec);
	static void SetEnemy(std::vector<UNUB> vec);

};

