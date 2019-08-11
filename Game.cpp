//
// Created by knip on 11/08/19.
//

#include "Game.h"
#include <iostream>

using namespace std;

int Game::Score (void)
{
    if (currentFrame == 0)
        return lastPins;
    else
        return ScoreForFrame(currentFrame);
}

int Game::CurrentFrame (void)
{
    return currentFrame;
}

void Game::Add(int pins)
{
    scorer.AddThrow(pins);
    AdjustCurrentFrame(pins);
    lastPins = pins;
}


bool Game::IsFrameCompleted  (int pins)
{
    return (IsStrike(pins) || !isFirstThrow);
}

bool Game::IsStrike (int pins)
{
    return (isFirstThrow && 10 == pins);
}

void Game::AdjustCurrentFrame (int pins)
{
    if (IsFrameCompleted(pins))
    {
        AdvanceFrame();
        isFirstThrow = true;
    }
    else
    {
        isFirstThrow = false;
    }
}

void Game::AdvanceFrame (void)
{
    currentFrame++;
    if (currentFrame > 10)
        currentFrame = 10;
}

int Game::ScoreForFrame (int frame)
{
    return scorer.ScoreForFrame(frame);
}

