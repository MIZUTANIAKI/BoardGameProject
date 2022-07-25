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
    //ã
    if (pos.y - 1 >= 0)
    {
        //¶
        if (pos.x - 1 >= 0)
        {
            movePos.emplace_back(pos.x - 1, pos.y - 1);
        }
        //‰E
        if (pos.x + 1 < 8)
        {
            movePos.emplace_back(pos.x + 1, pos.y - 1);
        }
    }
    //‰º
    if (pos.y + 1 < 8)
    {
        //¶
        if (pos.x - 1 >= 0)
        {
            movePos.emplace_back(pos.x - 1, pos.y + 1);
        }
        //‰E
        if (pos.x + 1 < 8)
        {
            movePos.emplace_back(pos.x + 1, pos.y + 1);
        }
    }
    //¶
    if (pos.x - 1 >= 0)
    {
        //ã
        if (pos.y - 1 >= 0)
        {
            movePos.emplace_back(pos.x - 1, pos.y - 1);
        }
        //‰º
        if (pos.y + 1 < 8)
        {
            movePos.emplace_back(pos.x - 1, pos.y + 1);
        }
    }
    //‰E
    if (pos.x + 1 < 8)
    {
        //ã
        if (pos.y - 1 >= 0)
        {
            movePos.emplace_back(pos.x + 1, pos.y - 1);
        }
        //‰º
        if (pos.y + 1 < 8)
        {
            movePos.emplace_back(pos.x + 1, pos.y + 1);
        }
    }
    return movePos;
}
