#include "MouseController.h"
#include <DxLib.h>

MouseController* MouseController::sInstance = nullptr;

MouseController::MouseController()
{
	mouseInput_.try_emplace(MOUSE_INPUT_LEFT, false);
	mouseInput_.try_emplace(MOUSE_INPUT_MIDDLE, false);
	mouseInput_.try_emplace(MOUSE_INPUT_RIGHT, false);
	mouseOldInput_ = mouseInput_;
}

MouseController::~MouseController()
{
}

void MouseController::Update()
{
	mouseOldInput_ = mouseInput_;
	DxLib::GetMousePoint(&mousePos_.x, &mousePos_.y);
	mouseInput_.at(MOUSE_INPUT_LEFT) = DxLib::GetMouseInput() & MOUSE_INPUT_LEFT;
	mouseInput_.at(MOUSE_INPUT_MIDDLE) = DxLib::GetMouseInput() & MOUSE_INPUT_MIDDLE;
	mouseInput_.at(MOUSE_INPUT_RIGHT) = DxLib::GetMouseInput() & MOUSE_INPUT_RIGHT;
}

Vector2 MouseController::GetMousePos()
{
	return mousePos_;
}

bool MouseController::GetMouseFlag(int num)
{
	if ((num != MOUSE_INPUT_LEFT) && (num != MOUSE_INPUT_MIDDLE) && (num != MOUSE_INPUT_RIGHT))
	{
		return false;
	}

	return mouseInput_.at(num);
}

bool MouseController::GetMouseTrg(int num)
{
	if ((num != MOUSE_INPUT_LEFT) && (num != MOUSE_INPUT_MIDDLE) && (num != MOUSE_INPUT_RIGHT))
	{
		return false;
	}

	return (!mouseOldInput_.at(num) && mouseInput_.at(num));
}
