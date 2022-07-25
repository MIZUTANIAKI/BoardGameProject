#include "Pawn.h"
#include "../Utility/BoardDate.h"
#include <array>

Pawn::~Pawn()
{
}

void Pawn::Update()
{
}

void Pawn::Draw(void)
{
}

std::vector<Vector2> Pawn::GetMovableDestination(void)
{
    std::vector<Vector2> movePos;
    auto date = BoardDate::GetBoard();
    Vector2 pos = pos_ / 60;
    if (pos.y - 1 >= 0)
    {
        if (date[pos.y - 1][pos.x] == Unit::non)
        {
            movePos.emplace_back(pos.x , pos.y - 1);
        }
        if (pos.x - 1 >= 0)
        {
            if (date[pos.y - 1][pos.x - 1] != Unit::non)
            {
                movePos.emplace_back(pos.x - 1, pos.y - 1);
            }
        }
        if (pos.x + 1 < 8)
        {
            if (date[pos.y - 1][pos.x + 1] != Unit::non)
            {
                movePos.emplace_back(pos.x + 1, pos.y - 1);
            }
        }
    }
    return movePos;
}
