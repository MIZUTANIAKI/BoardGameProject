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
	///	生成時にファイル指定していなかった場合に使用
	/// </summary>
	/// <param name="filename"></param>
	void OpenFile(std::string filename);

	std::vector<int> GetDate();

	int GetVal(std::string key);

private:
	std::map<std::string, int> valdat_;
	std::vector<int> dat_;
};
