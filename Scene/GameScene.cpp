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
	board_ = std::make_unique<Board>();
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
	DrawCube3D(VGet(0, 0, 0), VGet(100, 100, 100), 0xaf00ff, 0xaf00ff, true);
	board_->Draw();
}

SCN_ID GameScene::GetSCNID_(void)
{
	return scnID_;
}

