#pragma once
#include "BaseScene.h"
#include "Board.h"
#include "UnitBase.h"

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
	std::unique_ptr<Board> board_;
};

