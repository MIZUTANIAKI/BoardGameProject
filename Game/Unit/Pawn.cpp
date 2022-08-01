#include "Pawn.h"
#include "../Utility/BoardDate.h"
#include <array>

enum MoveMode
{
    mPawn,
    mQueen,
    mRook,
    mBishop,
    mKnight
};

Pawn::Pawn(Unit id) :UnitBase(id) 
{
    moveMode_ = MoveMode::mPawn;
};

Pawn::~Pawn()
{
}

void Pawn::Update()
{
    if (unitID_ <= Unit::wPawn8 && moveMode_ == MoveMode::mPawn)
    {
        if (pos_.y / 60 == 0)
        {
            moveMode_ = MoveMode::mQueen;
        }
    }
    else if (unitID_ >= Unit::bPawn1 && moveMode_ == MoveMode::mPawn)
    {
        if (pos_.y / 60 == 7)
        {
            moveMode_ = MoveMode::mQueen;
        }
    }
}

void Pawn::Draw(void)
{
    if (IsKillUnit())
    {
        return;
    }
    DxLib::DrawBox(pos_.x, pos_.y, pos_.x + 60, pos_.y + 60, 0x000000, true);
}

std::vector<Vector2> Pawn::GetMovableDestination(void)
{
    std::vector<Vector2> movePos;
    auto date = BoardDate::GetBoard();
    Vector2 pos = pos_ / 60;
    if (moveMode_ == MoveMode::mPawn)
    {
        MovePawn(pos, date, movePos);
    }
    else if (moveMode_ == MoveMode::mQueen)
    {
        MoveQueen(pos, date, movePos);
    }
    else if (moveMode_ == MoveMode::mRook)
    {
    }
    else if (moveMode_ == MoveMode::mBishop)
    {
    }
    else if (moveMode_ == MoveMode::mKnight)
    {
    }
    return movePos;
}

void Pawn::MoveQueen(Vector2& pos, std::array<std::array<Unit, 8Ui64>, 8Ui64>& date, std::vector<Vector2>& movePos)
{
    Vector2 nowpos = pos;
    //rook
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
    //bishop
    nowpos = pos;
    //‰Eã
    while (nowpos.x + 1 < 8 && nowpos.y - 1 >= 0)
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
    //‰E‰º
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
    //¶‰º
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
    //¶ã
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
}

void Pawn::MovePawn(Vector2& pos, std::array<std::array<Unit, 8Ui64>, 8Ui64>& date, std::vector<Vector2>& movePos)
{
    if (pos.y - 1 >= 0 && (unitID_ >= Unit::wPawn1 && unitID_ <= Unit::wPawn8))
    {
        if (date[pos.y - 1][pos.x] == Unit::non)
        {
            movePos.emplace_back(pos.x, pos.y - 1);
            if (pos.y == 6 && moveMode_ == MoveMode::mPawn && date[pos.y - 2][pos.x] == Unit::non)
            {
                movePos.emplace_back(pos.x, pos.y - 2);
            }
        }
        if (pos.x - 1 >= 0)
        {
            if (date[pos.y - 1][pos.x - 1] != Unit::non)
            {
                if (date[pos.y - 1][pos.x - 1] > Unit::wKing)
                {
                    movePos.emplace_back(pos.x - 1, pos.y - 1);
                }
            }
        }
        if (pos.x + 1 < 8)
        {
            if (date[pos.y - 1][pos.x + 1] != Unit::non)
            {
                if (date[pos.y - 1][pos.x + 1] > Unit::wKing)
                {
                    movePos.emplace_back(pos.x + 1, pos.y - 1);
                }
            }
        }
    }
    if (pos.y + 1 < 8 && (unitID_ >= Unit::bPawn1 && unitID_ <= Unit::bPawn8))
    {
        if (date[pos.y + 1][pos.x] == Unit::non)
        {
            movePos.emplace_back(pos.x, pos.y + 1);
            if (pos.y == 1 && moveMode_ == MoveMode::mPawn && date[pos.y + 2][pos.x] == Unit::non)
            {
                movePos.emplace_back(pos.x, pos.y + 2);
            }
        }
        if (pos.x - 1 >= 0)
        {
            if (date[pos.y + 1][pos.x - 1] != Unit::non)
            {
                if (date[pos.y + 1][pos.x - 1] <= Unit::wKing)
                {
                    movePos.emplace_back(pos.x - 1, pos.y + 1);
                }
            }
        }
        if (pos.x + 1 < 8)
        {
            if (date[pos.y + 1][pos.x + 1] != Unit::non)
            {
                if (date[pos.y + 1][pos.x + 1] <= Unit::wKing)
                {
                    movePos.emplace_back(pos.x + 1, pos.y + 1);
                }
            }
        }
    }

}
