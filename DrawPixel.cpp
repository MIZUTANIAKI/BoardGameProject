//#include "DxLib.h"
//
//// プログラムは WinMain から始まります
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	ChangeWindowMode(true);
//	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
//	{
//		return -1;			// エラーが起きたら直ちに終了
//	}
//
//
//	DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ
//
//	WaitKey();				// キー入力待ち
//
//    // 描画先を裏画面にする
//    SetDrawScreen(DX_SCREEN_BACK);
//    // Ｚバッファを有効にする
//    SetUseZBuffer3D(TRUE);
//
//    // Ｚバッファへの書き込みを有効にする
//    SetWriteZBuffer3D(TRUE);
//
//    VECTOR CameraPos;
//
//    // カメラの座標を初期化
//    CameraPos.x = 0.0f;
//    CameraPos.y = 0.0f;
//    CameraPos.z = -800.0f;
//
//    // ＥＳＣキーが押されるかウインドウが閉じられるまでループ
//    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
//    {
//        // 画面をクリア
//        ClearDrawScreen();
//
//        // 方向キーでカメラの座標を移動
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
//        // カメラの位置と注視点をセット、注視点は原点
//        SetCameraPositionAndTarget_UpVecY(CameraPos, VGet(0.0f, 0.0f, 0.0f));
//
//        for (int x = 0; x < 10; x++)
//        {
//            DrawSphere3D(VGet(x*500, 0, 0), 50.0f, 30, 0xffffff, 0xffffff, true);
//        }
//
//
//
//        // 裏画面の内容を表画面に反映
//        ScreenFlip();
//    }
//
//
//	DxLib_End();				// ＤＸライブラリ使用の終了処理
//
//	return 0;				// ソフトの終了 
//}
