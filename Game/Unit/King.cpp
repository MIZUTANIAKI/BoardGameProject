#include "King.h"
#include "../Utility/BoardDate.h"
#include <array>
#include "CheckBoard.h"

King::~King()
{
}

void King::Update()
{
}

void King::Draw(void)
{
    if (IsKillUnit())
    {
        return;
    }
    DxLib::DrawBox(pos_.x, pos_.y, pos_.x + 60, pos_.y + 60, 0x0000ff, false);
}

std::vector<Vector2> King::GetMovableDestination(void)
{   
    std::vector<Vector2> movePos;
    auto date = BoardDate::GetBoard();
    Vector2 pos = pos_ / 60;

    std::vector<Vector2> atackpos;
    if (unitID_ == Unit::wKing)
    {
        atackpos = CheckBoard::GetEnemyAtackPos();
    }
    else if (unitID_ == Unit::bKing)
    {
        atackpos = CheckBoard::GetPlayerAtackPos();
    }
    else
    {
        //ここに入るのは設定ミス
    }

    auto check = [&](const int& x,const int& y) {
        for (const auto& apos : atackpos)
        {
            if (x == apos.x && y == apos.y)
            {
                return false;
            }
        }
        return true;
    };

    //上
    if (pos.y - 1 >= 0)
    {
        //左
        if (pos.x - 1 >= 0)
        {
            if (date[pos.y - 1][pos.x - 1] == Unit::non && check(pos.y - 1, pos.x - 1))
            {
                movePos.emplace_back(pos.x - 1, pos.y - 1);
            }
        }
        //中央
        if (date[pos.y - 1][pos.x] == Unit::non && check(pos.y - 1, pos.x))
        {
            movePos.emplace_back(pos.x, pos.y - 1);
        }
        //右
        if (pos.x + 1 < 8)
        {
            if (date[pos.y - 1][pos.x + 1] == Unit::non && check(pos.y - 1, pos.x + 1))
            {
                movePos.emplace_back(pos.x + 1, pos.y - 1);
            }
        }
    }
    //中
        //左
    if (pos.x - 1 >= 0)
    {
        if (date[pos.y][pos.x - 1] == Unit::non && check(pos.y, pos.x - 1))
        {
            movePos.emplace_back(pos.x - 1, pos.y);
        }
    }
    //右
    if (pos.x + 1 < 8)
    {
        if (date[pos.y][pos.x + 1] == Unit::non && check(pos.y, pos.x + 1))
        {
            movePos.emplace_back(pos.x + 1, pos.y);
        }
    }
    //下
    if (pos.y + 1 < 8)
    {
        //左
        if (pos.x - 1 >= 0)
        {
            if (date[pos.y + 1][pos.x - 1] == Unit::non && check(pos.y + 1, pos.x - 1))
            {
                movePos.emplace_back(pos.x - 1, pos.y + 1);
            }
        }
        //中央
        if (date[pos.y + 1][pos.x] == Unit::non && check(pos.y + 1, pos.x))
        {
            movePos.emplace_back(pos.x, pos.y + 1);
        }
        //右
        if (pos.x + 1 < 8)
        {
            if (date[pos.y + 1][pos.x + 1] == Unit::non && check(pos.y + 1, pos.x + 1))
            {
                movePos.emplace_back(pos.x + 1, pos.y + 1);
            }
        }
    }
    return movePos;
}
