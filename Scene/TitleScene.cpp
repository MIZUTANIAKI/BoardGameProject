#include "TitleScene.h"
#include "GameScene.h"
#include "ImageMng.h"

TitleScene::TitleScene()
{
	scnID_ = SCN_ID::SCN_TITLE;
	title_ = LoadGraph("Resource/img/title.png");
}

TitleScene::~TitleScene()
{
}

UNBS TitleScene::Update(UNBS own)
{
	if (CheckHitKey(KEY_INPUT_G))
	{
		return std::move(std::make_unique<GameScene>());
	}
	return std::move(own);
}

void TitleScene::Draw(void)
{
	//DrawRotaGraph(60 * 8 / 2, 60 * 8 / 2, 0.5, 0, title_, true, 0, 0);
	DrawGraph(0, 0, title_, true);
	DrawString(1280/2-50, 720/2+150, "SPACE = スタート", 0xffffff);
	DrawString(1280/2, 720/2+250, "G = ミニゲーム", 0xffffff);
}

SCN_ID TitleScene::GetSCNID_(void)
{
	return scnID_;
}
