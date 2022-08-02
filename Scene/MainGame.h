#pragma once
#include "BaseScene.h"
class MainGame :
    public BaseScene
{
public:
	UNBS Update(UNBS own) override;
	MainGame();
	~MainGame();
	void Draw(void)override;
	SCN_ID GetSCNID_(void)override;
private:
};

