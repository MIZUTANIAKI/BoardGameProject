#include "Rook.h"
#include "../Utility/BoardDate.h"
#include <array>

Rook::~Rook()
{
}

void Rook::Update()
{
    //lpobjlMng.Setobjpos(modelID_, VGet(pos_.x + 30, pos_.y + 30, 0));
}

void Rook::Draw(void)
{
    if (IsKillUnit())
    {
        return;
    }
    //DxLib::DrawTriangle3D(VGet(pos_.x, pos_.y, 0), VGet(pos_.x + 60, pos_.y + 60, 0), VGet(pos_.x, pos_.y + 60, 0), 0xff0000, true);
    //DxLib::DrawTriangle3D(VGet(pos_.x, pos_.y, 0), VGet(pos_.x + 60, pos_.y, 0), VGet(pos_.x + 60, pos_.y + 60, 0), 0xff0000, true);
    DxLib::DrawBox(pos_.x, pos_.y, pos_.x + 60, pos_.y + 60, 0xff0000, true);
    //lpobjlMng.DrawSystem(lpobjlMng.GetModelHandle(modelID_));
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
    //‰E
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
    //ã
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
    //‰º
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
    return movePos;
}
