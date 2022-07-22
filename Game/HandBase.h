#pragma once
#include <array>
#include <vector>
#include <utility>
#include "Utility/Unit.h"
#include "Vector2.h"

enum class HandName
{
	Non,
	Player,
	Enemy,
};

class HandBase
{
public:
	HandBase();
	virtual ~HandBase();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <returns>true���ړ��挈��</returns>
	virtual bool Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	virtual void Draw();

	/// <summary>
	/// Update��true���������Ɏg�p�B
	/// ��������Ƃ��̈ړ�����
	/// </summary>
	/// <returns>UnitID�A�ړ���</returns>
	virtual std::pair<Unit, Vector2> NextMove();

	/// <summary>
	/// ���ʎ擾
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	HandName GetHandID(void);
private:

protected:
	/// <summary>
	/// ID�@���
	/// </summary>
	HandName handID_;
	std::pair<Unit, Vector2> nextPos_;
};

