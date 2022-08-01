#pragma once
#include "UnitBase.h"
class Pawn :
    public UnitBase
{
public:
	Pawn(Unit id);
	~Pawn();

	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param></param>
	/// <returns></returns>
	void Update() override;

	/// <summary>
	/// �`�揈��
	/// </summary>
	/// <param name=""></param>
	void Draw(void) override;

	/// <summary>
	/// �ړ��\����擾
	/// </summary>
	/// <param name=""></param>
	/// <returns>�ړ��\��̃��X�g�@����̏ꍇ�͖���</returns>
	std::vector<Vector2> GetMovableDestination(void) override;
	void MoveQueen(Vector2& pos, std::array<std::array<Unit, 8Ui64>, 8Ui64>& date, std::vector<Vector2>& movePos);
	void MovePawn(Vector2& pos, std::array<std::array<Unit, 8Ui64>, 8Ui64>& date, std::vector<Vector2>& movePos);

private:
	int moveMode_;	//�ړ����[�h
};

