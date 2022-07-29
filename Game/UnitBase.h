#pragma once
#include "Utility/Unit.h"
#include <memory>
#include <vector>
#include "Vector2.h"
#include <DxLib.h>

class UnitBase;
using UNUB = std::shared_ptr<UnitBase>;
class UnitBase
{
public:
	UnitBase();
	UnitBase(Unit id);
	virtual ~UnitBase();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param></param>
	/// <returns></returns>
	virtual void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	/// <param name=""></param>
	virtual void Draw(void);

	/// <summary>
	/// ���j�b�g��ʎ擾
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Unit GetUnitID(void);

	/// <summary>
	///	HP�擾
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	int GetHP(void);

	Vector2 GetPos();

	void SetPos(Vector2& pos);

	/// <summary>
	/// ���b�N���|����E�͂���
	/// </summary>
	/// <param name="isLock">true=Lock/false=UnLock</param>
	void SetLock(bool isLock);
	/// <summary>
	/// ���b�N�̏�Ԃ��擾
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	bool GetLock(void);

	/// <summary>
	/// �ړ��\����擾
	/// </summary>
	/// <param name=""></param>
	/// <returns>�ړ��\��̃��X�g�@����̏ꍇ�͖���</returns>
	virtual std::vector<Vector2> GetMovableDestination(void);

	void KillUnit(void);
private:
	/// <summary>
	/// �A�j���[�V�����Đ�
	/// </summary>
	/// <param name="num"></param>
	void PlayAnim(int num);

protected:
	/// <summary>
	/// ID�@���
	/// </summary>
	Unit unitID_;
	/// <summary>
	/// �q�b�g�|�C���g
	/// </summary>
	int hp_;
	/// <summary>
	/// �U����
	/// </summary>
	int attack_;
	/// <summary>
	/// �A�j���[�V����ID
	/// </summary>
	UnitAnimation animID_;
	/// <summary>
	/// ���W
	/// </summary>
	Vector2 pos_;
	/// <summary>
	/// ���b�N�@�ړ����\���ǂ���
	/// </summary>
	bool lock_;

	bool IsKillUnit(void);
};

