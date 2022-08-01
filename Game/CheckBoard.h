#pragma once
#include <vector>
#include "Vector2.h"
#include "UnitBase.h"

class CheckBoard
{
	static std::vector<Vector2> playerAtackPos_;
	static std::vector<Vector2> enemyAtackPos_;
	static bool checkPlayerKing_;
	static bool checkEnemyKing_;
public:
	CheckBoard();
	~CheckBoard();
	/// <summary>
	/// �v���C���[���U�����̃}�X���擾
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	static std::vector<Vector2> GetPlayerAtackPos(void);
	/// <summary>
	/// �G���U�����̃}�X���擾
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	static std::vector<Vector2> GetEnemyAtackPos(void);

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
	static void CheckAtackPos(void);

	/// <summary>
	/// ���񂮂��`�F�b�N����Ă��邩
	/// </summary>
	/// <param name="isPlayer">true = �v���C���[��</param>
	/// <returns></returns>
	static bool KingCheckNow(bool isPlayer = false);
	/// <summary>
	/// �L���O���`�F�b�N����Ă��邩�ǂ�����ݒ�
	/// </summary>
	/// <param name="now">���</param>
	/// <param name="isPlayer">true = �v���C���[��</param>
	static void SetCheckKing(bool now, bool isPlayer = false);
private:
	/// <summary>
	/// �U�����Ă���}�X���擾���ăZ�b�g
	/// </summary>
	/// <param name="units"></param>
	/// <param name="atackpos"></param>
	static void SetAtackPos(std::vector<UNUB>& units, std::vector<Vector2>& atackpos);
	static void CheckPawn(Vector2& pos, const UNUB& unit, std::vector<Vector2>& atackpos);
	static void CheckKing(Vector2& pos, std::vector<Vector2>& atackpos);
};

