#include <vector>
#include <tuple>
#include <string>
#include <map>
#include <DxLib.h>
#include "sceneMng.h"
#include "GameScene.h"
#include "CronoMng.h"
#include "FPSKeeper.h"
#include "ObjMng.h"
#include "ImageMng.h"
#include "SoundMng.h"
#include "MouseController.h"


SceneMng* SceneMng::sInstance = nullptr;


SceneMng::SceneMng() :ScreenSize{ 60 * 8 + 1,60 * 8 + 1/*1280,720*/ }
{
	SetWindowText("起動"); 

	lpImglMng.Create();
	lpSoundMng.Create();
	lpCronoMng.Create();
	lpobjlMng.Create();
	lpMouseMng.Create();
}

SceneMng::~SceneMng()
{
	lpImglMng.Destroy();
	lpobjlMng.Destroy();
	lpSoundMng.Destroy();
	lpCronoMng.Destroy();
	lpMouseMng.Destroy();
}

void SceneMng::Draw(void)
{
	DxLib::ClsDrawScreen();
	lpobjlMng.DrawNaw();


	activeScene_->Draw();
	
	DxLib::ScreenFlip();
}

void SceneMng::Run(void)
{
	SysInit();
	activeScene_ = std::make_unique<GameScene>();

	LPCSTR fontpath = "font/YuseiMagic-Regular.ttf";
	if (AddFontResourceEx(fontpath, FR_PRIVATE, NULL) <= 0)
	{
		MessageBox(NULL, "フォント読み込みに失敗", "フォント処理1", MB_OK);
		return;
	}
	ChangeFont("Yusei Magic", DX_CHARSET_DEFAULT);


	FPSKeeper* fps = new FPSKeeper();

	while (ProcessMessage() == 0&&CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		fps->Update();
		lpCronoMng.Start();
		lpImglMng.ReSetD();
		lpobjlMng.ReSetD();
		lpMouseMng.Update();
		//for (int i = 0; i < 2; i++)
		{
			activeScene_ = (*activeScene_).Update(std::move(activeScene_));
		}

		lpCronoMng.Last();

		Draw();
		fps->Wait();
	}

	if (RemoveFontResourceEx(fontpath, FR_PRIVATE, NULL))
	{
		//フォント破棄成功
	}
	else
	{
		MessageBox(NULL, "フォント破棄に失敗", "フォント処理2", MB_OK);
	}

	fontpath = NULL;
	delete fps;
}

bool SceneMng::SysInit(void)
{
	SetDXArchiveKeyString("DoAkathukiSoftWere");

	SetLightEnable(FALSE);

	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	SetGraphMode(ScreenSize.x, ScreenSize.y, 16);
	SetDrawScreen(DX_SCREEN_BACK);
	SetCreate3DSoundFlag(true);
	SetFontSize(60);
	SetBackgroundColor(50, 50, 50);
	SetUseZBufferFlag(TRUE);
	SetCameraNearFar(0.1f, 1000.0f);
	//SetMouseDispFlag(false);	//マウスを非表示に
	SetLightDifColor(GetColorF(1.0f, 1.0f, 1.0f, 0.0f));
	SetLightAmbColor(GetColorF(1.0f, 1.0f, 1.0f, 0.0f));

	SetFogEnable(TRUE);
	SetFogStartEnd(1500.0f, 40000.0f);

	SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 0.0f, -1000.0f), VGet(0.0f, 0.0f, 0.0f));

	return true;
}

