#include "MainGame.h"
#include <time.h>
#include <DxLib.h>
#include <vector>
#include <memory>
#include <string>
#include "ObjMng.h"
#include "SceneMng.h"
#include "WFUtility.h"


UNBS MainGame::Update(UNBS own)
{
    return std::move(own);
}

MainGame::MainGame()
{
    scnID_ = SCN_ID::SCN_GAME;
	lpobjlMng.LoadModel("UnitDef/UnitDef.mv1");
	MV1SetRotationXYZ(lpobjlMng.GetModelHandle(0), VGet(WFUtility::DegToRad(-110.0f), WFUtility::DegToRad(0.0f), WFUtility::DegToRad(180.0f)));
	MV1AttachAnim(lpobjlMng.GetModelHandle(0), 0, -1, FALSE);
}

MainGame::~MainGame()
{
}

void MainGame::Draw(void)
{
	DrawCube3D(VGet(0, 0, 0), VGet(100, 100, 100), 0xaf00ff, 0xaf00ff, true);
	MV1SetPosition(lpobjlMng.GetModelHandle(0), VGet(100, 100, 10));
	lpobjlMng.DrawSystem(lpobjlMng.GetModelHandle(0));

	for (int x = 0; x <= 8; x++)
	{
		for (int y = 0; y <= 8; y++)
		{
			DrawLine(x * 60, y * 60, x * 60 + 60, y * 60 + 60, 0xffffff);
			DrawLine(x * 60, y * 60, x * 60 + 60, y * 60, 0xffffff);
			DrawLine(x * 60, y * 60, x * 60, y * 60 + 60, 0xffffff);
		}
	}
}

SCN_ID MainGame::GetSCNID_(void)
{
    return scnID_;
}
