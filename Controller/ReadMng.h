#pragma once
#include <string>
#include <map>
#include <vector>

class ReadMng
{
public:
	ReadMng();
	ReadMng(std::string filename);
	~ReadMng();

	/// <summary>
	///	�������Ƀt�@�C���w�肵�Ă��Ȃ������ꍇ�Ɏg�p
	/// </summary>
	/// <param name="filename"></param>
	void OpenFile(std::string filename);

	std::vector<int> GetDate();

	int GetVal(std::string key);

private:
	std::map<std::string, int> valdat_;
	std::vector<int> dat_;
};
