#include "Player2Hand.h"
#include <DxLib.h>
#include "MouseController.h"
#include "UnitMng.h"
#include "Utility/BoardDate.h"
#include "CheckBoard.h"

Player2Hand::Player2Hand()
{
    handID_ = HandName::Player;
    lockTarget_ = false;
    lockUnit_ = Unit::non;
    nextPos_.first = Unit::non;
    nextPos_.second = Vector2(0, 0);
    movePosList_.clear();
}

Player2Hand::~Player2Hand()
{
}

bool Player2Hand::Update()
{

    if (lpMouseMng.GetMouseTrg(MOUSE_INPUT_RIGHT))
    {
        OutOfTarget();
    }

    {
        if (lpMouseMng.GetMouseTrg(MOUSE_INPUT_LEFT))
        {
            CheckTaget();
            if (lockTarget_)
            {
                return CheckMove();
            }
        }
    }

    return false;
}

void Player2Hand::OutOfTarget()
{
    lockTarget_ = false;
    nextPos_.first = Unit::non;
    nextPos_.second = Vector2(0, 0);
    movePosList_.clear();
}

void Player2Hand::Draw()
{
    if (lockTarget_)
    {
        for (const auto& pos : movePosList_)
        {
            DxLib::DrawBox(pos.x * 60, pos.y * 60, pos.x * 60 + 60, pos.y * 60 + 60, 0xff0000, true);
            DxLib::DrawLine(pos.x * 60 + 60, pos.y * 60, pos.x * 60, pos.y * 60 + 60, 0x000000, 2);
        }
    }
}

bool Player2Hand::CheckMove(void)
{
    Vector2 tpos = lpMouseMng.GetMousePos();
    tpos /= 60;
    if (tpos.x >= 8)
    {
        if (lpMouseMng.GetMouseFlag(MOUSE_INPUT_LEFT))
        {
            OutOfTarget();
        }
        return false;
    }
    if (tpos.y >= 8)
    {
        if (lpMouseMng.GetMouseFlag(MOUSE_INPUT_LEFT))
        {
            OutOfTarget();
        }
        return false;
    }
    auto playerlist = UnitMng::GetEnemy();
    for (const auto& uni : playerlist)
    {
        if (uni->GetUnitID() == lockUnit_)
        {
            movePosList_ = std::move(uni->GetMovableDestination());
            if (movePosList_.empty())
            {
                lockTarget_ = false;
                nextPos_.first = Unit::non;
                nextPos_.second = Vector2(0, 0);
                return false;
            }
            if (!lpMouseMng.GetMouseTrg(MOUSE_INPUT_LEFT))
            {
                return false;
            }
            for (const auto& pos : movePosList_)
            {
                if (pos == tpos)
                {
                    if (CheckBoard::KingCheckNow(false))
                    {
                        Vector2 tmpPos = uni->GetPos();
                        auto tmpBoard = BoardDate::GetBoard();
                        BoardDate::SetDate(uni->GetPos(), tpos);
                        uni->SetPos(tpos);
                        CheckBoard::CheckAtackPos();
                        if (lockUnit_ != Unit::bKing)
                        {
                            for (auto& tuni : playerlist)
                            {
                                if (tuni->GetUnitID() == Unit::bKing)
                                {
                                    tuni->GetMovableDestination();
                                    break;
                                }
                            }
                        }
                        else
                        {
                            uni->GetMovableDestination();
                        }
                        BoardDate::SetDate(tmpBoard);
                        uni->SetPos(tmpPos);
                        if (CheckBoard::KingCheckNow(false))
                        {
                            return false;
                        }
                        CheckBoard::CheckAtackPos();
                    }
                    nextPos_.first = lockUnit_;
                    nextPos_.second = pos;
                    return true;
                }
            }
        }
    }
    return false;
}

bool Player2Hand::CheckTaget(void)
{
    nextPos_.first = Unit::non;
    nextPos_.second = Vector2(0, 0);
    Vector2 tpos = lpMouseMng.GetMousePos();
    tpos /= 60;
    if (tpos.x >= 8)
    {
        OutOfTarget();
        return false;
    }
    if (tpos.y >= 8)
    {
        OutOfTarget();
        return false;
    }
    //target‚ÌUnit‚ð“®‚©‚·‚½‚ß‚ÉA“®‚¢‚Ä‚à‚æ‚¢‚©“™‚ð”»’èB
    auto playerlist = UnitMng::GetEnemy();

    for (const auto& uni : playerlist)
    {
        if (uni->GetPos() == tpos)
        {
            if (uni->GetLock())
            {
                return false;
            }
            lockUnit_ = uni->GetUnitID();
            lockTarget_ = true;
            return false;
        }
    }
    return false;
}

std::pair<Unit, Vector2> Player2Hand::NextMove()
{
    auto pos = nextPos_;
    OutOfTarget();
    return pos;
}
