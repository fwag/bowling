//
// Created by knip on 11/08/19.
//

#ifndef BOWLING_GAME_H
#define BOWLING_GAME_H

#include "Scorer.h"

class Game {
private:
    int currentFrame;
    bool isFirstThrow;
    Scorer scorer;
    int lastPins;

public:
    Game() : currentFrame(0),
             isFirstThrow(true),
             lastPins(0)
    {}

    int Score (void);
    bool IsFrameCompleted (int pins);
    bool IsStrike (int pins);
    int CurrentFrame (void);
    void AdvanceFrame (void);
    void AdjustCurrentFrame (int pins);
    void Add (int pins);
    int ScoreForFrame (int frame);
};


#endif //BOWLING_GAME_H
