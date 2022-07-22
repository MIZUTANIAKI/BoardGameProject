#pragma once
#include <Map>
#include "Vector2.h"

#define lpMouseMng MouseController::GetInstance()

class MouseController
{
	static MouseController* sInstance;
	Vector2 mousePos_;
	std::map<int, bool> mouseInput_;
	std::map<int, bool> mouseOldInput_;

	MouseController();
	~MouseController();
public:
	static MouseController& GetInstance(void)
	{

		Create();
		return *sInstance;
	}

	static void Create()
	{
		if (sInstance == nullptr)
		{
			sInstance = new MouseController();
		}
	}

	static void Destroy()
	{
		if (sInstance != nullptr)
		{
			delete sInstance;
		}
		sInstance = nullptr;
	}

	void Update();

	Vector2 GetMousePos();
	bool GetMouseFlag(int num);
	bool GetMouseTrg(int num);
};