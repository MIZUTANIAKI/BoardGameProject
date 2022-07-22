#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "ReadMng.h"

ReadMng::ReadMng()
{
}

ReadMng::ReadMng(std::string filename)
{
	OpenFile(filename);
}

ReadMng::~ReadMng()
{
}

void ReadMng::OpenFile(std::string filename)
{
	std::ifstream ifs(filename);

	if (ifs.fail())
	{
		return;
	}
	std::string str;
	while (getline(ifs, str))
	{
		std::stringstream ss(str);
		std::string tstr;
		getline(ss,tstr,':');
		if (tstr != "date")
		{
			std::string tmstr;
			getline(ss, tmstr, ':');
			valdat_.try_emplace(tstr, atoi(tmstr.c_str()));
		}
		else
		{
			std::vector<int> tvec;

			std::string tmstr;
			getline(ss, tmstr, ':');
			std::stringstream tss(tmstr);
			while (getline(tss, tmstr, ','))
			{
				tvec.emplace_back(atoi(tmstr.c_str()));
			}

			dat_.swap(tvec);
		}

	}
}

std::vector<int> ReadMng::GetDate()
{
	return dat_;
}

int ReadMng::GetVal(std::string key)
{
	for (const auto& dat : valdat_)
	{
		if (dat.first == key)
		{
			return dat.second;
		}
	}
	return -1;
}
