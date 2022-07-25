#include "Bishop.h"
#include "../Utility/BoardDate.h"
#include <array>

Bishop::~Bishop()
{
}

void Bishop::Update()
{
}

void Bishop::Draw(void)
{
}

std::vector<Vector2> Bishop::GetMovableDestination(void)
{
    std::vector<Vector2> movePos;
    auto date = BoardDate::GetBoard();
    Vector2 pos = pos_ / 60;
    Vector2 nowpos = pos;
    //‰Eã
    while (nowpos.x + 1 >= 0 && nowpos.y - 1 >= 0)
    {
        nowpos.x += 1;
        nowpos.y -= 1;
        movePos.emplace_back(nowpos.x, nowpos.y);
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            break;
        }
    }
    nowpos = pos;
    //‰E‰º
    while (nowpos.x + 1 < 8 && nowpos.y + 1 < 8)
    {
        nowpos.x += 1;
        nowpos.y += 1;
        movePos.emplace_back(nowpos.x, nowpos.y);
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            break;
        }
    }
    nowpos = pos;
    //¶‰º
    while (nowpos.x - 1 >= 0 && nowpos.y + 1 < 8)
    {
        nowpos.x -= 1;
        nowpos.y += 1;
        movePos.emplace_back(nowpos.x, nowpos.y);
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            break;
        }
    }
    nowpos = pos;
    //¶ã
    while (nowpos.x - 1 >= 0 && nowpos.y - 1 >= 0)
    {
        nowpos.x -= 1;
        nowpos.y -= 1;
        movePos.emplace_back(nowpos.x, nowpos.y);
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            break;
        }
    }
    return movePos;
}
