#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Game.h"

TEST_CASE( "Bowling - test one throw", "[one-throw]" )
{
    Game game;
    game.Add(5);
    REQUIRE(5 == game.Score());
}

TEST_CASE( "Bowling - test two throws no mark", "[two-throws]" )
{
    Game game;
    game.Add(5);
    game.Add(4);
    REQUIRE(9 == game.Score());
    REQUIRE(1 == game.CurrentFrame());
}

TEST_CASE( "Bowling - test four throws no mark", "[four-throws]" )
{
    Game game;
    game.Add(3);
    game.Add(7);
    game.Add(3);
    REQUIRE(13 == game.ScoreForFrame(1));
}

TEST_CASE( "Bowling - test simple spare", "[simple-spare]" )
{
    Game game;
    game.Add(5);
    game.Add(4);
    game.Add(7);
    game.Add(2);
    REQUIRE(18 == game.Score());
    REQUIRE(9 == game.ScoreForFrame(1));
    REQUIRE(18 ==  game.ScoreForFrame(2));
}

TEST_CASE( "Bowling - test simple frame after spare", "[simple-frame-after-spare]")
{
    Game game;
    game.Add(3);
    game.Add(7);
    game.Add(3);
    game.Add(2);
    REQUIRE(13 == game.ScoreForFrame(1));
    REQUIRE(18 == game.Score());
    REQUIRE(2 == game.CurrentFrame());
}

TEST_CASE( "Bowling - test simple strike", "[simple-strike]")
{
    Game game;
    game.Add(10);
    game.Add(3);
    game.Add(6);
    REQUIRE(19 == game.ScoreForFrame(1));
    REQUIRE(28 == game.Score());
    REQUIRE(2 == game.CurrentFrame());
}

TEST_CASE ( "Bowling - test perfect game", "[perfect-game]")
{
    Game game;
    for (int i = 0; i < 12; i++)
        game.Add(10);
    REQUIRE(300 ==  game.Score());
    REQUIRE(10 == game.CurrentFrame());
}

TEST_CASE( "Bowling - test end of array", "[end-of-array]")
{
    Game game;
    for (int i=0; i<9; i++)
    {
        game.Add(0);
        game.Add(0);
    }
    game.Add(2);
    game.Add(8); // 10th frame spare
    game.Add(10); // Strike in last position of array.
    REQUIRE(20 == game.Score());
}

TEST_CASE ( "Bowling - test sample game", "[sample-game]")
{
    Game game;
    game.Add(1);
    game.Add(4);
    game.Add(4);
    game.Add(5);
    game.Add(6);
    game.Add(4);
    game.Add(5);
    game.Add(5);
    game.Add(10);
    game.Add(0);
    game.Add(1);
    game.Add(7);
    game.Add(3);
    game.Add(6);
    game.Add(4);
    game.Add(10);
    game.Add(2);
    game.Add(8);
    game.Add(6);
    REQUIRE(133 == game.Score());
}

TEST_CASE( "Bowling - test heart break game", "[heart-break-game]")
{
    Game game;
    for (int i = 0; i < 11; i++)
        game.Add(10);

    game.Add(9);
    REQUIRE(299 == game.Score());
}

TEST_CASE ( "Bowling - test tenth frame spare", "[tenth-frame-spare]")
{
    Game game;
    for (int i = 0; i < 9; i++)
        game.Add(10);

    game.Add(9);
    game.Add(1);
    game.Add(1);
    REQUIRE(270 == game.Score());
}