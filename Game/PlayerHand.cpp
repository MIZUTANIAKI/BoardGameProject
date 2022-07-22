#include "PlayerHand.h"
#include <DxLib.h>
#include "MouseController.h"
#include "UnitMng.h"
#include "Utility/BoardDate.h"

PlayerHand::PlayerHand()
{
    handID_ = HandName::Player;
    lockTarget_ = false;
    lockUnit_ = Unit::non;
    nextPos_.first=Unit::non;
    nextPos_.second = Vector2(0, 0);
}

PlayerHand::~PlayerHand()
{
}

bool PlayerHand::Update()
{
    if (lpMouseMng.GetMouseTrg(MOUSE_INPUT_LEFT))
    {
        if (!lockTarget_)
        {
            return CheckTaget();
        }
        else
        {
            return CheckMove();
        }
    }
    if (lpMouseMng.GetMouseTrg(MOUSE_INPUT_RIGHT))
    {
        lockTarget_ = false;
        nextPos_.first = Unit::non;
        nextPos_.second = Vector2(0, 0);
    }
    return false;
}

void PlayerHand::Draw()
{
    if (lockTarget_)
    {
        for (const auto& pos : movePosList_)
        {
            DxLib::DrawBox(pos.x, pos.y, pos.x + 60, pos.y + 60, 0xff0000, true);
        }
    }
}

bool PlayerHand::CheckMove(void)
{
    Vector2 tpos = lpMouseMng.GetMousePos();
    tpos /= 60;
    if (tpos.x >= 8)
    {
        return false;
    }
    if (tpos.y >= 8)
    {
        return false;
    }
    auto playerlist = UnitMng::GetPlayer();
    for (const auto& uni : playerlist)
    {
        if (uni->GetUnitID() == lockUnit_)
        {
            movePosList_ = std::move(uni->GetMovableDestination());
            if (movePosList_.empty())
            {
                lockTarget_ = false;
                return false;
            }
            for (const auto& pos : movePosList_)
            {
                if (pos == tpos)
                {
                    nextPos_.first = lockUnit_;
                    nextPos_.second = pos;
                    return true;
                }
            }
            lockTarget_ = false;
        }
    }

    return false;
}

bool PlayerHand::CheckTaget(void)
{
    nextPos_.first = Unit::non;
    nextPos_.second = Vector2(0, 0);
    Vector2 tpos = lpMouseMng.GetMousePos();
    tpos /= 60;
    if (tpos.x >= 8)
    {
        return false;
    }
    if (tpos.y >= 8)
    {
        return false;
    }
    Unit target = BoardDate::GetBoard()[tpos.y][tpos.x];
    if (target <= Unit::non && target >= Unit::bPawn1)
    {
        return false;
    }

    //target‚ÌUnit‚ð“®‚©‚·‚½‚ß‚ÉA“®‚¢‚Ä‚à‚æ‚¢‚©“™‚ð”»’èB
    auto playerlist = UnitMng::GetPlayer();
    for (const auto& uni : playerlist)
    {
        if (uni->GetUnitID() == target)
        {
            if (uni->GetLock())
            {
                return false;
            }
            lockUnit_ = target;
            lockTarget_ = true;
            return false;
        }
    }
    return false;
}

std::pair<Unit, Vector2> PlayerHand::NextMove()
{
    return nextPos_;
}
