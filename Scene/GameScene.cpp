#include <time.h>
#include <DxLib.h>
#include <vector>
#include <memory>
#include "GameScene.h"
#include "SceneMng.h"

GameScene::GameScene()
{
	SetWindowText("::ÉQÅ[ÉÄ");
	srand((unsigned)time(NULL));
	scnID_ = SCN_ID::SCN_GAME;

	{
		SetFogColor(100, 100, 100);
	}
	board_ = std::make_unique<Board>(0);
}

UNBS GameScene::Update(UNBS own)
{
	board_->Update();
	return std::move(own);
}


GameScene::~GameScene()
{
}

void GameScene::Draw(void)
{
	//DrawCube3D(VGet(0, 0, 0), VGet(100, 100, 100), 0xaf00ff, 0xaf00ff, true);
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

