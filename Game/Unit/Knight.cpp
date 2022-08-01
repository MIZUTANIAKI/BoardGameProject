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
    if (IsKillUnit())
    {
        return;
    }
    DxLib::DrawBox(pos_.x, pos_.y, pos_.x + 60, pos_.y + 60, 0xffff00, true);
}

std::vector<Vector2> Knight::GetMovableDestination(void)
{
    std::vector<Vector2> movePos;
    auto date = BoardDate::GetBoard();
    Vector2 pos = pos_ / 60;
    //ã
    if (pos.y - 2 >= 0)
    {
        //¶
        if (pos.x - 1 >= 0)
        {
            if ((unitID_ <= Unit::wKing && date[pos.y - 2][pos.x - 1] > Unit::wKing) || (unitID_ > Unit::wKing && date[pos.y - 2][pos.x - 1] <= Unit::wKing) || date[pos.y - 2][pos.x - 1] == Unit::non)
            {
                movePos.emplace_back(pos.x - 1, pos.y - 2);
            }
        }
        //‰E
        if (pos.x + 1 < 8)
        {
            if ((unitID_ <= Unit::wKing && date[pos.y - 2][pos.x + 1] > Unit::wKing) || (unitID_ > Unit::wKing && date[pos.y - 2][pos.x + 1] <= Unit::wKing) || date[pos.y - 2][pos.x + 1] == Unit::non)
            {
                movePos.emplace_back(pos.x + 1, pos.y - 2);
            }
        }
    }
    //‰º
    if (pos.y + 2 < 8)
    {
        //¶
        if (pos.x - 1 >= 0)
        {
            if ((unitID_ <= Unit::wKing && date[pos.y + 2][pos.x - 1] > Unit::wKing) || (unitID_ > Unit::wKing && date[pos.y + 2][pos.x - 1] <= Unit::wKing) || date[pos.y + 2][pos.x - 1] == Unit::non)
            {
                movePos.emplace_back(pos.x - 1, pos.y + 2);
            }
        }
        //‰E
        if (pos.x + 1 < 8)
        {
            if ((unitID_ <= Unit::wKing && date[pos.y + 2][pos.x + 1] > Unit::wKing) || (unitID_ > Unit::wKing && date[pos.y + 2][pos.x + 1] <= Unit::wKing) || date[pos.y + 2][pos.x + 1] == Unit::non)
            {
                movePos.emplace_back(pos.x + 1, pos.y + 2);
            }
        }
    }
    //¶
    if (pos.x - 2 >= 0)
    {
        //ã
        if (pos.y - 1 >= 0)
        {
            if ((unitID_ <= Unit::wKing && date[pos.y - 1][pos.x - 2] > Unit::wKing) || (unitID_ > Unit::wKing && date[pos.y - 1][pos.x - 2] <= Unit::wKing) || date[pos.y - 1][pos.x - 2] == Unit::non)
            {
                movePos.emplace_back(pos.x - 2, pos.y - 1);
            }
        }
        //‰º
        if (pos.y + 1 < 8)
        {
            if ((unitID_ <= Unit::wKing && date[pos.y + 1][pos.x - 2] > Unit::wKing) || (unitID_ > Unit::wKing && date[pos.y + 1][pos.x - 2] <= Unit::wKing) || date[pos.y + 1][pos.x - 2] == Unit::non)
            {
                movePos.emplace_back(pos.x - 2, pos.y + 1);
            }
        }
    }
    //‰E
    if (pos.x + 2 < 8)
    {
        //ã
        if (pos.y - 1 >= 0)
        {
            if ((unitID_ <= Unit::wKing && date[pos.y - 1][pos.x + 2] > Unit::wKing) || (unitID_ > Unit::wKing && date[pos.y - 1][pos.x + 2] <= Unit::wKing) || date[pos.y - 1][pos.x + 2] == Unit::non)
            {
                movePos.emplace_back(pos.x + 2, pos.y - 1);
            }
        }
        //‰º
        if (pos.y + 1 < 8)
        {
            if ((unitID_ <= Unit::wKing && date[pos.y + 1][pos.x + 2] > Unit::wKing) || (unitID_ > Unit::wKing && date[pos.y + 1][pos.x + 2] <= Unit::wKing) || date[pos.y + 1][pos.x + 2] == Unit::non)
            {
                movePos.emplace_back(pos.x + 2, pos.y + 1);
            }
        }
    }
    return movePos;
}
