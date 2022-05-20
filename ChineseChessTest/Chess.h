#pragma once

#include <vector>
#include <string>
//#include "ChessBoard.h"
#include "Point.h"

class ChessBoard;

class Chess {
protected:
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
    virtual std::vector<Point> canMoveTo(Chess***) = 0;

    /// <summary>
    /// Get this Chess where can attack.
    /// </summary>
    /// <returns></returns>
    virtual std::vector<Point> canAttackTo(Chess***) = 0;

    virtual std::string toString() = 0;

    virtual int getTeam();

    virtual bool isGeneral();

    virtual void SetPoint(Point);
};

class General : public Chess {
public:
    General(int, Point);
    std::vector<Point> canMoveTo(Chess***);
    std::vector<Point> canAttackTo(Chess***);
    std::string toString();
    virtual bool isGeneral() override;
};

class Advisor : public Chess {
public:
    Advisor(int, Point);
    std::vector<Point> canMoveTo(Chess***);
    std::vector<Point> canAttackTo(Chess***);
    std::string toString();
};

class Elephant : public Chess {
public:
    Elephant(int, Point);
    std::vector<Point> canMoveTo(Chess***);
    std::vector<Point> canAttackTo(Chess***);
    std::string toString();
};

class Horse : public Chess {
public:
    Horse(int, Point);
    std::vector<Point> canMoveTo(Chess***);
    std::vector<Point> canAttackTo(Chess***);
    std::string toString();
};

class Chariot : public Chess {
public:
    Chariot(int, Point);
    std::vector<Point> canMoveTo(Chess***);
    std::vector<Point> canAttackTo(Chess***);
    std::string toString();
};

class Cannon : public Chess {
public:
    Cannon(int, Point);
    std::vector<Point> canMoveTo(Chess***);
    std::vector<Point> canAttackTo(Chess***);
    std::string toString();
};

class Soldier : public Chess {
public:
    Soldier(int, Point);
    std::vector<Point> canMoveTo(Chess***);
    std::vector<Point> canAttackTo(Chess***);
    std::string toString();
};
