#include "Knight.h"
#include "../Utility/BoardDate.h"
#include <array>

Knight::~Knight()
{
}

void Knight::Update()
{
    //lpobjlMng.Setobjpos(modelID_, VGet(pos_.x + 30, pos_.y + 30, 0));
}

void Knight::Draw(void)
{
    if (IsKillUnit())
    {
        return;
    }

    DxLib::DrawBox(pos_.x, pos_.y, pos_.x + 60, pos_.y + 60, 0xffff00, true);
    //DxLib::DrawTriangle3D(VGet(pos_.x, pos_.y, 0), VGet(pos_.x + 60, pos_.y + 60, 0), VGet(pos_.x, pos_.y + 60, 0), 0xffff00, true);
    //DxLib::DrawTriangle3D(VGet(pos_.x, pos_.y, 0), VGet(pos_.x + 60, pos_.y, 0), VGet(pos_.x + 60, pos_.y + 60, 0), 0xffff00, true);
    //lpobjlMng.DrawSystem(lpobjlMng.GetModelHandle(modelID_));
}

std::vector<Vector2> Knight::GetMovableDestination(void)
{
    std::vector<Vector2> movePos;
    auto date = BoardDate::GetBoard();
    Vector2 pos = pos_ / 60;
    //上
    if (pos.y - 2 >= 0)
    {
        //左
        if (pos.x - 1 >= 0)
        {
            if ((unitID_ <= Unit::wKing && date[pos.y - 2][pos.x - 1] > Unit::wKing) || (unitID_ > Unit::wKing && date[pos.y - 2][pos.x - 1] <= Unit::wKing) || date[pos.y - 2][pos.x - 1] == Unit::non)
            {
                movePos.emplace_back(pos.x - 1, pos.y - 2);
            }
        }
        //右
        if (pos.x + 1 < 8)
        {
            if ((unitID_ <= Unit::wKing && date[pos.y - 2][pos.x + 1] > Unit::wKing) || (unitID_ > Unit::wKing && date[pos.y - 2][pos.x + 1] <= Unit::wKing) || date[pos.y - 2][pos.x + 1] == Unit::non)
            {
                movePos.emplace_back(pos.x + 1, pos.y - 2);
            }
        }
    }
    //下
    if (pos.y + 2 < 8)
    {
        //左
        if (pos.x - 1 >= 0)
        {
            if ((unitID_ <= Unit::wKing && date[pos.y + 2][pos.x - 1] > Unit::wKing) || (unitID_ > Unit::wKing && date[pos.y + 2][pos.x - 1] <= Unit::wKing) || date[pos.y + 2][pos.x - 1] == Unit::non)
            {
                movePos.emplace_back(pos.x - 1, pos.y + 2);
            }
        }
        //右
        if (pos.x + 1 < 8)
        {
            if ((unitID_ <= Unit::wKing && date[pos.y + 2][pos.x + 1] > Unit::wKing) || (unitID_ > Unit::wKing && date[pos.y + 2][pos.x + 1] <= Unit::wKing) || date[pos.y + 2][pos.x + 1] == Unit::non)
            {
                movePos.emplace_back(pos.x + 1, pos.y + 2);
            }
        }
    }
    //左
    if (pos.x - 2 >= 0)
    {
        //上
        if (pos.y - 1 >= 0)
        {
            if ((unitID_ <= Unit::wKing && date[pos.y - 1][pos.x - 2] > Unit::wKing) || (unitID_ > Unit::wKing && date[pos.y - 1][pos.x - 2] <= Unit::wKing) || date[pos.y - 1][pos.x - 2] == Unit::non)
            {
                movePos.emplace_back(pos.x - 2, pos.y - 1);
            }
        }
        //下
        if (pos.y + 1 < 8)
        {
            if ((unitID_ <= Unit::wKing && date[pos.y + 1][pos.x - 2] > Unit::wKing) || (unitID_ > Unit::wKing && date[pos.y + 1][pos.x - 2] <= Unit::wKing) || date[pos.y + 1][pos.x - 2] == Unit::non)
            {
                movePos.emplace_back(pos.x - 2, pos.y + 1);
            }
        }
    }
    //右
    if (pos.x + 2 < 8)
    {
        //上
        if (pos.y - 1 >= 0)
        {
            if ((unitID_ <= Unit::wKing && date[pos.y - 1][pos.x + 2] > Unit::wKing) || (unitID_ > Unit::wKing && date[pos.y - 1][pos.x + 2] <= Unit::wKing) || date[pos.y - 1][pos.x + 2] == Unit::non)
            {
                movePos.emplace_back(pos.x + 2, pos.y - 1);
            }
        }
        //下
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
