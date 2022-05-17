#pragma once

#include <vector>
//#include "ChessBoard.h"
#include "Point.h"

class ChessBoard;

class Chess {
    Point position;
    int team;
    //Asset
    //PicLocation
public:
    Chess();
    /// <summary>
    /// Just Constructor Ok?
    /// </summary>
    /// <param name=""></param>
    /// <param name=""></param>
    Chess(int, Point);

    /// <summary>
    /// Get this Chess where can go.
    /// </summary>
    /// <returns></returns>
    virtual std::vector<Point> canMoveTo(Chess****);

    /// <summary>
    /// Get this Chess where can attack.
    /// </summary>
    /// <returns></returns>
    virtual std::vector<Point> canAttackTo(Chess****);

    virtual int getTeam();
};

class General : public Chess {

};

class Advisor : public Chess {

};

class Elephant : public Chess {

};

class Horse : public Chess {

};

class Chariot : public Chess {

};

class Cannon : public Chess {

};

class Soldier : public Chess {

};
