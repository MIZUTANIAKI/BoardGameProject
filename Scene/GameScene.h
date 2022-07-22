#pragma once
#include "BaseScene.h"

class ExampleMap;

class GameScene :
	public BaseScene
{
public:
	UNBS Update(UNBS own) override;
	GameScene();
	~GameScene();
	void Draw(void)override;
	SCN_ID GetSCNID_(void)override;
private:
};

