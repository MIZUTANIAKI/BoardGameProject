#include "Knight.h"
#include "../Utility/BoardDate.h"
#include <array>

Knight::Knight()
{
}

Knight::~Knight()
{
}

void Knight::Update()
{
}

void Knight::Draw(void)
{
}

std::vector<Vector2> Knight::GetMovableDestination(void)
{
    std::vector<Vector2> movePos;
    auto date = BoardDate::GetBoard();
    Vector2 pos = pos_ / 60;
    return movePos;
}
