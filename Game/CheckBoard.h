#pragma once
#include <vector>
#include "Vector2.h"

class CheckBoard
{
	std::vector<Vector2> playerAtackPos_;
	std::vector<Vector2> enemyAtackPos_;
public:
	CheckBoard();
	~CheckBoard();
	/// <summary>
	/// �v���C���[���U�����̃}�X���擾
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	std::vector<Vector2> GetPlayerAtackPos(void);
	/// <summary>
	/// �G���U�����̃}�X���擾
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	std::vector<Vector2> GetEnemyAtackPos(void);

	/// <summary>
	/// �Ֆʂ����b�N����Ă����Ԃ��ǂ���
	/// true�Ȃ�X�e�C�����C�g�ň�������
	/// </summary>
	/// <param name=""></param>
	/// <returns>true=���b�N</returns>
	bool IsDeadLock(void);

	/// <summary>
	/// �`�F�b�N���C�g���Ă��邩
	/// </summary>
	/// <param name=""></param>
	/// <returns>0=�� 1=�v���C���[ 2=�G</returns>
	int IsCheckMate(void);

	/// <summary>
	/// �U�����̍X�V
	/// </summary>
	/// <param name=""></param>
	void CheckAtackPos(void);
	void SetAtackPos(std::vector<UNUB>& units, std::vector<Vector2>& atackpos);
private:
};

