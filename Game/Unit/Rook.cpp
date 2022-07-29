#include "Rook.h"
#include "../Utility/BoardDate.h"
#include <array>

Rook::~Rook()
{
}

void Rook::Update()
{
}

void Rook::Draw(void)
{
    if (IsKillUnit())
    {
        return;
    }
    DxLib::DrawBox(pos_.x, pos_.y, pos_.x + 60, pos_.y + 60, 0xff0000, false);
}

std::vector<Vector2> Rook::GetMovableDestination(void)
{
    std::vector<Vector2> movePos;
    auto date = BoardDate::GetBoard();
    Vector2 pos = pos_ / 60;
    Vector2 nowpos = pos;
    //¶
    while (nowpos.x - 1 >= 0)
    {
        nowpos.x -= 1;
        movePos.emplace_back(nowpos.x, nowpos.y);
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            break;
        }
    }
    nowpos = pos;
    //‰E
    while (nowpos.x + 1 < 8)
    {
        nowpos.x += 1;
        movePos.emplace_back(nowpos.x, nowpos.y);
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            break;
        }
    }
    nowpos = pos;
    //ã
    while (nowpos.y - 1 >= 0)
    {
        nowpos.y -= 1;
        movePos.emplace_back(nowpos.x, nowpos.y);
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            break;
        }
    }
    nowpos = pos;
    //‰º
    while (nowpos.y + 1 < 8)
    {
        nowpos.y += 1;
        movePos.emplace_back(nowpos.x, nowpos.y);
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            break;
        }
    }
    return movePos;
}
