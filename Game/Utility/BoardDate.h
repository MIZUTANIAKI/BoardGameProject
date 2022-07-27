#pragma once
#include <array>
#include <vector>
#include "Unit.h"
#include "Vector2.h"

class BoardDate
{
	static std::array<std::array<Unit, 8>, 8> boardDate_;
public:
	/// <summary>
	/// ��������ƂɃf�[�^���擾
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <returns></returns>
	static Unit GatDate(int& x, int& y);
	/// <summary>
	/// �{�[�h���̂��擾
	/// </summary>
	/// <returns></returns>
	static std::array<std::array<Unit, 8>, 8> GetBoard();

	/// <summary>
	/// �f�[�^�ݒ�@�w�c�P�ʂŏ�����
	/// </summary>
	/// <param name="isPlayer"></param>
	/// <param name="date"></param>
	void SetDate(bool isPlayer, std::vector<int> date);
	/// <summary>
	/// �f�[�^�ݒ� �{�[�h�{�̏㏑��
	/// </summary>
	/// <param name="dat"></param>
	void SetDate(std::array<std::array<Unit, 8>, 8> dat);
	/// <summary>
	/// �f�[�^�ݒ�@���j�b�g�ړ��p/�ړ������ړ����
	/// </summary>
	/// <param name="from"></param>
	/// <param name="to"></param>
	void SetDate(Vector2 from, Vector2 to);

	BoardDate();
	~BoardDate();
};

