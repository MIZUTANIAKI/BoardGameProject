#include <time.h>
#include <DxLib.h>
#include <vector>
#include <memory>
#include "GameScene.h"
#include "ObjMng.h"
#include "SceneMng.h"
#include "WFUtility.h"

GameScene::GameScene()
{
	/*SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 0.0f, -500.0f), VGet(0.0f, 0.0f, 0.0f));*/
	//SetupCamera_Perspective(60 * DX_PI_F / 180.0f);
	//SetCameraPositionAndTargetAndUpVec(VGet(GetCameraPosition().x, GetCameraPosition().y, GetCameraPosition().z), VGet(GetCameraTarget().x, GetCameraTarget().y-0.01f, GetCameraTarget().z), VGet(sin(WFUtility::DegToRad(0.0f)), cos(WFUtility::DegToRad(0.0f)), GetCameraUpVector().z));
	SetWindowText("::ÉQÅ[ÉÄ");
	srand((unsigned)time(NULL));
	scnID_ = SCN_ID::SCN_GAME;

	{
		SetFogColor(100, 100, 100);
	}
	lpobjlMng.LoadModel("UnitDef/UnitDef.mv1");
	MV1SetRotationXYZ(lpobjlMng.GetModelHandle(0), VGet(WFUtility::DegToRad(-110.0f), WFUtility::DegToRad(0.0f), WFUtility::DegToRad(180.0f)));
	board_ = std::make_unique<Board>(0);

	SetGraphMode(60 * 8 + 1, 60 * 8 + 1, 16);
}

UNBS GameScene::Update(UNBS own)
{
	board_->Update();
	SetupCamera_Ortho(480.0f);
	/*SetCameraPositionAndTarget_UpVecY(VGet(60.0f*8, -60.0f*8, -1000.0f), VGet(60.0f * 8, -60.0f * 8, 0.0f));*/
	return std::move(own);
}


GameScene::~GameScene()
{
}

void GameScene::Draw(void)
{
	//DrawCube3D(VGet(0, 0, 0), VGet(100, 100, 100), 0xaf00ff, 0xaf00ff, true);
	//MV1SetPosition(lpobjlMng.GetModelHandle(0), VGet(100, 100, 10));
	//lpobjlMng.DrawSystem(lpobjlMng.GetModelHandle(0));

	board_->Draw();
	for (int x = 0; x <= 8; x++)
	{
		for (int y = 0; y <= 8; y++)
		{
			DxLib::DrawLine(x * 60, y * 60, x * 60 + 60, y * 60 + 60, 0xffffff);
			DxLib::DrawLine(x * 60, y * 60, x * 60 + 60, y * 60, 0xffffff);
			DxLib::DrawLine(x * 60, y * 60, x * 60, y * 60 + 60, 0xffffff);
		}
	}
}

SCN_ID GameScene::GetSCNID_(void)
{
	return scnID_;
}

