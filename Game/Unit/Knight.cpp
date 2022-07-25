#include "Knight.h"
#include "../Utility/BoardDate.h"
#include <array>

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
    //上
    if (pos.y - 1 >= 0)
    {
        //左
        if (pos.x - 1 >= 0)
        {
            movePos.emplace_back(pos.x - 1, pos.y - 1);
        }
        //右
        if (pos.x + 1 < 8)
        {
            movePos.emplace_back(pos.x + 1, pos.y - 1);
        }
    }
    //下
    if (pos.y + 1 < 8)
    {
        //左
        if (pos.x - 1 >= 0)
        {
            movePos.emplace_back(pos.x - 1, pos.y + 1);
        }
        //右
        if (pos.x + 1 < 8)
        {
            movePos.emplace_back(pos.x + 1, pos.y + 1);
        }
    }
    //左
    if (pos.x - 1 >= 0)
    {
        //上
        if (pos.y - 1 >= 0)
        {
            movePos.emplace_back(pos.x - 1, pos.y - 1);
        }
        //下
        if (pos.y + 1 < 8)
        {
            movePos.emplace_back(pos.x - 1, pos.y + 1);
        }
    }
    //右
    if (pos.x + 1 < 8)
    {
        //上
        if (pos.y - 1 >= 0)
        {
            movePos.emplace_back(pos.x + 1, pos.y - 1);
        }
        //下
        if (pos.y + 1 < 8)
        {
            movePos.emplace_back(pos.x + 1, pos.y + 1);
        }
    }
    return movePos;
}
