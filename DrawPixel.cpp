//#include "DxLib.h"
//
//// �v���O������ WinMain ����n�܂�܂�
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	ChangeWindowMode(true);
//	if (DxLib_Init() == -1)		// �c�w���C�u��������������
//	{
//		return -1;			// �G���[���N�����璼���ɏI��
//	}
//
//
//	DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�
//
//	WaitKey();				// �L�[���͑҂�
//
//    // �`���𗠉�ʂɂ���
//    SetDrawScreen(DX_SCREEN_BACK);
//    // �y�o�b�t�@��L���ɂ���
//    SetUseZBuffer3D(TRUE);
//
//    // �y�o�b�t�@�ւ̏������݂�L���ɂ���
//    SetWriteZBuffer3D(TRUE);
//
//    VECTOR CameraPos;
//
//    // �J�����̍��W��������
//    CameraPos.x = 0.0f;
//    CameraPos.y = 0.0f;
//    CameraPos.z = -800.0f;
//
//    // �d�r�b�L�[��������邩�E�C���h�E��������܂Ń��[�v
//    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
//    {
//        // ��ʂ��N���A
//        ClearDrawScreen();
//
//        // �����L�[�ŃJ�����̍��W���ړ�
//        if (CheckHitKey(KEY_INPUT_UP) == 1)
//        {
//            CameraPos.y += 20.0f;
//        }
//        if (CheckHitKey(KEY_INPUT_DOWN) == 1)
//        {
//            CameraPos.y -= 20.0f;
//        }
//        if (CheckHitKey(KEY_INPUT_LEFT) == 1)
//        {
//            CameraPos.x -= 20.0f;
//        }
//        if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
//        {
//            CameraPos.x += 20.0f;
//        }
//
//        // �J�����̈ʒu�ƒ����_���Z�b�g�A�����_�͌��_
//        SetCameraPositionAndTarget_UpVecY(CameraPos, VGet(0.0f, 0.0f, 0.0f));
//
//        for (int x = 0; x < 10; x++)
//        {
//            DrawSphere3D(VGet(x*500, 0, 0), 50.0f, 30, 0xffffff, 0xffffff, true);
//        }
//
//
//
//        // ����ʂ̓��e��\��ʂɔ��f
//        ScreenFlip();
//    }
//
//
//	DxLib_End();				// �c�w���C�u�����g�p�̏I������
//
//	return 0;				// �\�t�g�̏I�� 
//}
