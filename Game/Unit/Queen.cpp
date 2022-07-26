#include "Queen.h"
#include "../Utility/BoardDate.h"
#include <array>

Queen::~Queen()
{
}

void Queen::Update()
{
    //lpobjlMng.Setobjpos(modelID_, VGet(pos_.x + 30, pos_.y + 30, 0));
}

void Queen::Draw(void)
{
    if (IsKillUnit())
    {
        return;
    }
    //DxLib::DrawTriangle3D(VGet(pos_.x, pos_.y, 0), VGet(pos_.x + 60, pos_.y + 60, 0), VGet(pos_.x, pos_.y + 60, 0), 0x00ff00, true);
    //DxLib::DrawTriangle3D(VGet(pos_.x, pos_.y, 0), VGet(pos_.x + 60, pos_.y, 0), VGet(pos_.x + 60, pos_.y + 60, 0), 0x00ff00, true);

    DxLib::DrawBox(pos_.x, pos_.y, pos_.x + 60, pos_.y + 60, 0x00ff00, true);
    //lpobjlMng.DrawSystem(lpobjlMng.GetModelHandle(modelID_));
}

std::vector<Vector2> Queen::GetMovableDestination(void)
{
    std::vector<Vector2> movePos;
    auto date = BoardDate::GetBoard();
    Vector2 pos = pos_ / 60;
    Vector2 nowpos = pos;
    //rook
    //左
    while (nowpos.x - 1 >= 0)
    {
        nowpos.x -= 1;
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            if ((unitID_ <= Unit::wKing && date[nowpos.y][nowpos.x] > Unit::wKing) || (unitID_ > Unit::wKing && date[nowpos.y][nowpos.x] <= Unit::wKing))
            {
                movePos.emplace_back(nowpos.x, nowpos.y);
            }
            break;
        }
        movePos.emplace_back(nowpos.x, nowpos.y);
    }
    nowpos = pos;
    //右
    while (nowpos.x + 1 < 8)
    {
        nowpos.x += 1;
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            if ((unitID_ <= Unit::wKing && date[nowpos.y][nowpos.x] > Unit::wKing) || (unitID_ > Unit::wKing && date[nowpos.y][nowpos.x] <= Unit::wKing))
            {
                movePos.emplace_back(nowpos.x, nowpos.y);
            }
            break;
        }
        movePos.emplace_back(nowpos.x, nowpos.y);
    }
    nowpos = pos;
    //上
    while (nowpos.y - 1 >= 0)
    {
        nowpos.y -= 1;
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            if ((unitID_ <= Unit::wKing && date[nowpos.y][nowpos.x] > Unit::wKing) || (unitID_ > Unit::wKing && date[nowpos.y][nowpos.x] <= Unit::wKing))
            {
                movePos.emplace_back(nowpos.x, nowpos.y);
            }
            break;
        }
        movePos.emplace_back(nowpos.x, nowpos.y);
    }
    nowpos = pos;
    //下
    while (nowpos.y + 1 < 8)
    {
        nowpos.y += 1;
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            if ((unitID_ <= Unit::wKing && date[nowpos.y][nowpos.x] > Unit::wKing) || (unitID_ > Unit::wKing && date[nowpos.y][nowpos.x] <= Unit::wKing))
            {
                movePos.emplace_back(nowpos.x, nowpos.y);
            }
            break;
        }
        movePos.emplace_back(nowpos.x, nowpos.y);
    }
    //bishop
    nowpos = pos;
    //右上
    while (nowpos.x + 1 < 8&& nowpos.y - 1 >= 0)
    {
        nowpos.x += 1;
        nowpos.y -= 1;
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            if ((unitID_ <= Unit::wKing && date[nowpos.y][nowpos.x] > Unit::wKing) || (unitID_ > Unit::wKing && date[nowpos.y][nowpos.x] <= Unit::wKing))
            {
                movePos.emplace_back(nowpos.x, nowpos.y);
            }
            break;
        }
        movePos.emplace_back(nowpos.x, nowpos.y);
    }
    nowpos = pos;
    //右下
    while (nowpos.x + 1 < 8 && nowpos.y + 1 < 8)
    {
        nowpos.x += 1;
        nowpos.y += 1;
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            if ((unitID_ <= Unit::wKing && date[nowpos.y][nowpos.x] > Unit::wKing) || (unitID_ > Unit::wKing && date[nowpos.y][nowpos.x] <= Unit::wKing))
            {
                movePos.emplace_back(nowpos.x, nowpos.y);
            }
            break;
        }
        movePos.emplace_back(nowpos.x, nowpos.y);
    }
    nowpos = pos;
    //左下
    while (nowpos.x - 1 >= 0 && nowpos.y + 1 < 8)
    {
        nowpos.x -= 1;
        nowpos.y += 1;
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            if ((unitID_ <= Unit::wKing && date[nowpos.y][nowpos.x] > Unit::wKing) || (unitID_ > Unit::wKing && date[nowpos.y][nowpos.x] <= Unit::wKing))
            {
                movePos.emplace_back(nowpos.x, nowpos.y);
            }
            break;
        }
        movePos.emplace_back(nowpos.x, nowpos.y);
    }
    nowpos = pos;
    //左上
    while (nowpos.x - 1 >= 0 && nowpos.y - 1 >= 0)
    {
        nowpos.x -= 1;
        nowpos.y -= 1;
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            if ((unitID_ <= Unit::wKing && date[nowpos.y][nowpos.x] > Unit::wKing) || (unitID_ > Unit::wKing && date[nowpos.y][nowpos.x] <= Unit::wKing))
            {
                movePos.emplace_back(nowpos.x, nowpos.y);
            }
            break;
        }
        movePos.emplace_back(nowpos.x, nowpos.y);
    }
    return movePos;
}
