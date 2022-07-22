#pragma once
#include "HandBase.h"
#include "Vector2.h"
#include <Vector>
#include "Utility/Unit.h"

class PlayerHand :
    public HandBase
{
public:
	PlayerHand();
	virtual ~PlayerHand();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <returns>true���ړ��挈��</returns>
	bool Update() override;

	void Draw() override;

	/// <summary>
	/// Update��true���������Ɏg�p�B
	/// ��������Ƃ��̈ړ�����
	/// </summary>
	/// <returns>UnitID�A�ړ���</returns>
	std::pair<Unit, Vector2> NextMove() override;
private:
	bool lockTarget_;
	Unit lockUnit_; 
	std::vector<Vector2> movePosList_;

	/// <summary>
	/// target�����߂ă}�E�X�����N���b�N�����B
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool CheckMove(void);
	/// <summary>
	/// �܂�target�����߂ĂȂ��Ƃ��Ƀ}�E�X�����N���b�N�����B
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool CheckTaget(void);
};

