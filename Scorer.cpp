//
// Created by knip on 11/08/19.
//

#include "Scorer.h"

void Scorer::AddThrow (int pins)
{
    throws[currentThrow++] = pins;
}

bool Scorer::IsStrike (void)
{
    return (10 == throws[ball]);
}

bool Scorer::IsSpare (void)
{
    return (10 == (throws[ball]+throws[ball+1]));
}

int Scorer::NextTwoBallsForStrike (void)
{
    return (throws[ball+1] + throws[ball+2]);
}

int Scorer::NextBallForSpare (void)
{
    return throws[ball+2];
}

int Scorer::TwoBallsInFrame (void)
{
    return (throws[ball] + throws[ball+1]);
}

int Scorer::ScoreForFrame (int frame)
{
    int score = 0;
    ball = 0;
    for (int currentFrame = 0;
         currentFrame < frame;
         currentFrame++)
    {

        if (IsStrike())
        {
            score += 10 + NextTwoBallsForStrike();
            ball += 1;
        } else if (IsSpare()) {
            score += 10 + NextBallForSpare();
            ball += 2;
        } else {
            score += TwoBallsInFrame();
            ball += 2;
        }
    }

    return score;
}
