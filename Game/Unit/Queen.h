#pragma once
#include "UnitBase.h"
class Queen :
    public UnitBase
{
public:
	Queen();
	~Queen();

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
};

