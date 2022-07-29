#include "Queen.h"
#include "../Utility/BoardDate.h"
#include <array>

Queen::~Queen()
{
}

void Queen::Update()
{
}

void Queen::Draw(void)
{
    if (IsKillUnit())
    {
        return;
    }
    DxLib::DrawBox(pos_.x, pos_.y, pos_.x + 60, pos_.y + 60, 0x00ff00, false);
}

std::vector<Vector2> Queen::GetMovableDestination(void)
{
    std::vector<Vector2> movePos;
    auto date = BoardDate::GetBoard();
    Vector2 pos = pos_ / 60;
    Vector2 nowpos = pos;
    //rook
    //��
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
    //�E
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
    //��
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
    //��
    while (nowpos.y + 1 < 8)
    {
        nowpos.y += 1;
        movePos.emplace_back(nowpos.x, nowpos.y);
        if (date[nowpos.y][nowpos.x] != Unit::non)
        {
            break;
        }
    }
    //bishop
    nowpos = pos;
    //�E��
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
    //�E��
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
    //����
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
    //����
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
    //king
    //��
    if (pos.y - 1 >= 0)
    {
        //��
        if (pos.x - 1 >= 0)
        {
            movePos.emplace_back(pos.x - 1, pos.y - 1);
        }
        //����
        movePos.emplace_back(pos.x, pos.y - 1);
        //�E
        if (pos.x + 1 < 8)
        {
            movePos.emplace_back(pos.x + 1, pos.y - 1);
        }
    }
    //��
        //��
    if (pos.x - 1 >= 0)
    {
        movePos.emplace_back(pos.x - 1, pos.y);
    }
        //�E
    if (pos.x + 1 < 8)
    {
        movePos.emplace_back(pos.x + 1, pos.y);
    }
    //��
    if (pos.y + 1 < 8)
    {
        //��
        if (pos.x - 1 >= 0)
        {
            movePos.emplace_back(pos.x - 1, pos.y + 1);
        }
        //����
        movePos.emplace_back(pos.x, pos.y + 1);
        //�E
        if (pos.x + 1 < 8)
        {
            movePos.emplace_back(pos.x + 1, pos.y + 1);
        }
    }
    return movePos;
}
