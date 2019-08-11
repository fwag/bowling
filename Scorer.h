//
// Created by knip on 11/08/19.
//

#ifndef BOWLING_SCORER_H
#define BOWLING_SCORER_H

#include <vector>

class Scorer {
private:
    int ball;
    std::vector<int> throws;
    int currentThrow;
public:
    Scorer() : throws(21),
               currentThrow(0)
    {}
    void AddThrow (int pins);
    bool IsStrike (void);
    bool IsSpare (void);
    int NextTwoBallsForStrike (void);
    int NextBallForSpare (void);
    int TwoBallsInFrame (void);
    int ScoreForFrame (int frame);
};


#endif //BOWLING_SCORER_H
