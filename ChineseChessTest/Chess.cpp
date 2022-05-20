#include "Chess.h"
#include <string>

class ChessBoard;

//Chess::Chess() {
//
//}

Chess::Chess() {
}

Chess::Chess(int team, Point pos) {
    this->team = team;
    position = pos;
}

std::vector<Point> Chess::canMoveTo(Chess***) {
    return std::vector<Point>();
}

std::vector<Point> Chess::canAttackTo(Chess***) {
    return std::vector<Point>();
}

int Chess::getTeam() {
    return team;
}

bool Chess::isGeneral() {
    return false;
}

void Chess::SetPoint(Point p) {
    this->position = p;
}

General::General(int team, Point pos) {
    this->team = team;
    position = pos;
}

std::vector<Point> General::canMoveTo(Chess*** cb) {
    std::vector<Point> v;
    if (getTeam()) {
        if (position.x > 5 && cb[position.x - 1][position.y] == nullptr) {
            v.push_back(Point(position.x - 1, position.y));
        }
        if (position.x < 7 && cb[position.x + 1][position.y] == nullptr) {
            v.push_back(Point(position.x + 1, position.y));
        }
        if (position.y > 9 && cb[position.x][position.y - 1] == nullptr) {
            v.push_back(Point(position.x, position.y - 1));
        }
        if (position.y < 11 && cb[position.x][position.y + 1] == nullptr) {
            v.push_back(Point(position.x, position.y + 1));
        }
    } else {
        if (position.x > 5 && cb[position.x - 1][position.y] == nullptr) {
            v.push_back(Point(position.x - 1, position.y));
        }
        if (position.x < 7 && cb[position.x + 1][position.y] == nullptr) {
            v.push_back(Point(position.x + 1, position.y));
        }
        if (position.y > 2 && cb[position.x][position.y - 1] == nullptr) {
            v.push_back(Point(position.x, position.y - 1));
        }
        if (position.y < 4 && cb[position.x][position.y + 1] == nullptr) {
            v.push_back(Point(position.x, position.y + 1));
        }
    }
    return v;
}

std::vector<Point> General::canAttackTo(Chess*** cb) {
    std::vector<Point> v;
    if (getTeam()) {
        if (position.x > 5 && cb[position.x - 1][position.y] != nullptr) {
            if (!cb[position.x - 1][position.y]->getTeam())
                v.push_back(Point(position.x - 1, position.y));
        }
        if (position.x < 7 && cb[position.x + 1][position.y] != nullptr) {
            if (!cb[position.x + 1][position.y]->getTeam())
            v.push_back(Point(position.x + 1, position.y));
        }
        if (position.y > 9 && cb[position.x][position.y - 1] != nullptr) {
            if (!cb[position.x][position.y - 1]->getTeam())
            v.push_back(Point(position.x, position.y - 1));
        }
        if (position.y < 11 && cb[position.x][position.y + 1] != nullptr) {
            if (!cb[position.x][position.y + 1]->getTeam())
            v.push_back(Point(position.x, position.y + 1));
        }
        for (int i = position.y - 1; i > 1; i--) {
            if (cb[position.x][i] != nullptr) {
                if (cb[position.x][i]->isGeneral()) {
                    v.push_back(Point(position.x, i));
                }
                break;
            }
        }
    } else {
        if (position.x > 5 && cb[position.x - 1][position.y] != nullptr) {
            if (cb[position.x - 1][position.y]->getTeam())
                v.push_back(Point(position.x - 1, position.y));
        }
        if (position.x < 7 && cb[position.x + 1][position.y] != nullptr) {
            if (cb[position.x + 1][position.y]->getTeam())
                v.push_back(Point(position.x + 1, position.y));
        }
        if (position.y > 2 && cb[position.x][position.y - 1] != nullptr) {
            if (cb[position.x][position.y - 1]->getTeam())
                v.push_back(Point(position.x, position.y - 1));
        }
        if (position.y < 4 && cb[position.x][position.y + 1] != nullptr) {
            if (cb[position.x][position.y + 1]->getTeam())
                v.push_back(Point(position.x, position.y + 1));
        }
        for (int i = position.y + 1; i < 12; i++) {
            if (cb[position.x][i] != nullptr) {
                if (cb[position.x][i]->isGeneral()) {
                    v.push_back(Point(position.x, i));
                }
                break;
            }
        }
    }
    return v;
}

std::string General::toString() {
    return getTeam() ? "g" : "G";
}

bool General::isGeneral() {
    return true;
}

Advisor::Advisor(int team, Point pos) {
    this->team = team; position = pos;
}

std::vector<Point> Advisor::canMoveTo(Chess*** cb) {
    std::vector<Point> v;
    if (getTeam()) {
        if (position.x == 6 && position.y == 10) {
            if (cb[5][9] == nullptr)
                v.push_back(Point(5, 9));
            if (cb[5][11] == nullptr)
                v.push_back(Point(5, 11));
            if (cb[7][9] == nullptr)
                v.push_back(Point(7, 9));
            if (cb[7][11] == nullptr)
                v.push_back(Point(7, 11));
        } else {
            if (cb[6][10] == nullptr)
                v.push_back(Point(6, 10));
        }
    } else {
        if (position.x == 6 && position.y == 3) {
            if (cb[5][2] == nullptr)
                v.push_back(Point(5, 2));
            if (cb[5][4] == nullptr)
                v.push_back(Point(5, 4));
            if (cb[7][2] == nullptr)
                v.push_back(Point(7, 2));
            if (cb[7][4] == nullptr)
                v.push_back(Point(7, 4));
        } else {
            if (cb[6][3] == nullptr)
                v.push_back(Point(6, 3));
        }
    }
    return v;
}

std::vector<Point> Advisor::canAttackTo(Chess*** cb) {
    std::vector<Point> v;
    if (getTeam()) {
        if (position.x == 6 && position.y == 10) {
            if (cb[5][9] != nullptr)
                v.push_back(Point(5, 9));
            if (cb[5][11] != nullptr)
                v.push_back(Point(5, 11));
            if (cb[7][9] != nullptr)
                v.push_back(Point(7, 9));
            if (cb[7][11] != nullptr)
                v.push_back(Point(7, 11));
        } else {
            if (cb[6][10] != nullptr)
                v.push_back(Point(6, 10));
        }
    } else {
        if (position.x == 6 && position.y == 3) {
            if (cb[5][2] != nullptr)
                v.push_back(Point(5, 2));
            if (cb[5][4] != nullptr)
                v.push_back(Point(5, 4));
            if (cb[7][2] != nullptr)
                v.push_back(Point(7, 2));
            if (cb[7][4] != nullptr)
                v.push_back(Point(7, 4));
        } else {
            if (cb[6][3] != nullptr)
                v.push_back(Point(6, 3));
        }
    }
    return v;
}

std::string Advisor::toString() {
    return getTeam() ? "f" : "F";
}

Elephant::Elephant(int team, Point pos) {
    this->team = team; position = pos;
}

std::vector<Point> Elephant::canMoveTo(Chess*** cb) {
    std::vector<Point> v, w;
    if (cb[position.x - 1][position.y - 1] == nullptr && cb[position.x - 2][position.y - 2] == nullptr)
        v.push_back(Point(position.x - 2, position.y - 2));
    if (cb[position.x - 1][position.y + 1] == nullptr && cb[position.x - 2][position.y + 2] == nullptr)
        v.push_back(Point(position.x - 2, position.y + 2));
    if (cb[position.x + 1][position.y - 1] == nullptr && cb[position.x + 2][position.y - 2] == nullptr)
        v.push_back(Point(position.x + 2, position.y - 2));
    if (cb[position.x + 1][position.y + 1] == nullptr && cb[position.x + 2][position.y + 2] == nullptr)
        v.push_back(Point(position.x + 2, position.y + 2));
    if (getTeam()) {
        for (Point vv : v) {
            if (!vv.NotVaild() && vv.y > 6) {
                w.push_back(vv);
            }
        }
    } else {
        for (Point vv : v) {
            if (!vv.NotVaild() && vv.y < 7) {
                w.push_back(vv);
            }
        }
    }
    return w;
}

std::vector<Point> Elephant::canAttackTo(Chess*** cb) {
    std::vector<Point> v, w;
    if (cb[position.x - 1][position.y - 1] == nullptr && cb[position.x - 2][position.y - 2] != nullptr)
        v.push_back(Point(position.x - 2, position.y - 2));
    if (cb[position.x - 1][position.y + 1] == nullptr && cb[position.x - 2][position.y + 2] != nullptr)
        v.push_back(Point(position.x - 2, position.y + 2));
    if (cb[position.x + 1][position.y - 1] == nullptr && cb[position.x + 2][position.y - 2] != nullptr)
        v.push_back(Point(position.x + 2, position.y - 2));
    if (cb[position.x + 1][position.y + 1] == nullptr && cb[position.x + 2][position.y + 2] != nullptr)
        v.push_back(Point(position.x + 2, position.y + 2));
    if (getTeam()) {
        for (Point vv : v) {
            if (!vv.NotVaild() && vv.y > 6 && !cb[vv.x][vv.y]->getTeam()) {
                w.push_back(vv);
            }
        }
    } else {
        for (Point vv : v) {
            if (!vv.NotVaild() && vv.y < 7 && cb[vv.x][vv.y]->getTeam()) {
                w.push_back(vv);
            }
        }
    }
    return w;
}

std::string Elephant::toString() {
    return getTeam() ? "e" : "E";
}

Horse::Horse(int team, Point pos) {
    this->team = team; position = pos;
}

std::vector<Point> Horse::canMoveTo(Chess*** cb) {
    std::vector<Point> v, w;
    if (cb[position.x - 1][position.y] == nullptr) {
        if (cb[position.x - 2][position.y - 1] == nullptr)
            v.push_back(Point(position.x - 2, position.y - 1));
        if (cb[position.x - 2][position.y + 1] == nullptr)
            v.push_back(Point(position.x - 2, position.y + 1));
    }
    if (cb[position.x][position.y - 1] == nullptr) {
        if (cb[position.x - 1][position.y - 2] == nullptr)
            v.push_back(Point(position.x - 1, position.y - 2));
        if (cb[position.x + 1][position.y - 2] == nullptr)
            v.push_back(Point(position.x + 1, position.y - 2));
    }
    if (cb[position.x + 1][position.y] == nullptr) {
        if (cb[position.x + 2][position.y - 1] == nullptr)
            v.push_back(Point(position.x + 2, position.y - 1));
        if (cb[position.x + 2][position.y + 1] == nullptr)
            v.push_back(Point(position.x + 2, position.y - 1));
    }
    if (cb[position.x][position.y + 1] == nullptr) {
        if (cb[position.x - 1][position.y + 2] == nullptr)
            v.push_back(Point(position.x - 1, position.y + 2));
        if (cb[position.x + 1][position.y + 2] == nullptr)
            v.push_back(Point(position.x + 1, position.y + 2));
    }
    for (Point vv : v) {
        if (!vv.NotVaild()) {
            w.push_back(vv);
        }
    }
    return w;
}

std::vector<Point> Horse::canAttackTo(Chess*** cb) {
    std::vector<Point> v, w;
    if (cb[position.x - 1][position.y] == nullptr) {
        if (cb[position.x - 2][position.y - 1] != nullptr)
            if (cb[position.x - 2][position.y - 1]->getTeam() != getTeam())
            v.push_back(Point(position.x - 2, position.y - 1));
        if (cb[position.x - 2][position.y + 1] != nullptr)
            if (cb[position.x - 2][position.y + 1]->getTeam() != getTeam())
            v.push_back(Point(position.x - 2, position.y + 1));
    }
    if (cb[position.x][position.y - 1] == nullptr) {
        if (cb[position.x - 1][position.y - 2] != nullptr)
            if (cb[position.x - 1][position.y - 2]->getTeam() != getTeam())
            v.push_back(Point(position.x - 1, position.y - 2));
        if (cb[position.x + 1][position.y - 2] != nullptr)
            if (cb[position.x + 1][position.y - 2]->getTeam() != getTeam())
            v.push_back(Point(position.x + 1, position.y - 2));
    }
    if (cb[position.x + 1][position.y] == nullptr) {
        if (cb[position.x + 2][position.y - 1] != nullptr)
            if (cb[position.x + 2][position.y - 1]->getTeam() != getTeam())
            v.push_back(Point(position.x + 2, position.y - 1));
        if (cb[position.x + 2][position.y + 1] != nullptr)
            if (cb[position.x + 2][position.y + 1]->getTeam() != getTeam())
            v.push_back(Point(position.x + 2, position.y - 1));
    }
    if (cb[position.x][position.y + 1] == nullptr) {
        if (cb[position.x - 1][position.y + 2] != nullptr)
            if (cb[position.x - 1][position.y + 2]->getTeam() != getTeam())
            v.push_back(Point(position.x - 1, position.y + 2));
        if (cb[position.x + 1][position.y + 2] != nullptr)
            if (cb[position.x + 1][position.y + 2]->getTeam() != getTeam())
            v.push_back(Point(position.x + 1, position.y + 2));
    }
    for (Point vv : v) {
        if (!vv.NotVaild()) {
            w.push_back(vv);
        }
    }
    return w;
}

std::string Horse::toString() {
    return getTeam() ? "c" : "C";
}

Chariot::Chariot(int team, Point pos) {
    this->team = team; position = pos;
}

std::vector<Point> Chariot::canMoveTo(Chess*** cb) {
    std::vector<Point> v, w;
    for (int i = position.x - 1; i > 1; i--) {
        if (cb[i][position.y] == nullptr) {
            v.push_back(Point(i, position.y));
        } else {
            break;
        }
    }
    for (int i = position.x + 1; i < 11; i++) {
        if (cb[i][position.y] == nullptr) {
            v.push_back(Point(i, position.y));
        } else {
            break;
        }
    }
    for (int i = position.y - 1; i > 1; i--) {
        if (cb[position.x][i] == nullptr) {
            v.push_back(Point(position.x, i));
        } else {
            break;
        }
    }
    for (int i = position.y + 1; i < 12; i++) {
        if (cb[position.x][i] == nullptr) {
            v.push_back(Point(position.x, i));
        } else {
            break;
        }
    }
    for (Point vv : v) {
        if (!vv.NotVaild()) {
            w.push_back(vv);
        }
    }
    return w;
}

std::vector<Point> Chariot::canAttackTo(Chess*** cb) {
    std::vector<Point> v, w;
    for (int i = position.x - 1; i > 1; i--) {
        if (cb[i][position.y] == nullptr) {
        } else {
            if (cb[i][position.y]->getTeam() != getTeam())
                v.push_back(Point(i, position.y));
            break;
        }
    }
    for (int i = position.x + 1; i < 11; i++) {
        if (cb[i][position.y] == nullptr) {
        } else {
            if (cb[i][position.y]->getTeam() != getTeam())
                v.push_back(Point(i, position.y));
            break;
        }
    }
    for (int i = position.y - 1; i > 1; i--) {
        if (cb[position.x][i] == nullptr) {
        } else {
            if (cb[position.x][i]->getTeam() != getTeam())
                v.push_back(Point(position.x, i));
            break;
        }
    }
    for (int i = position.y + 1; i < 12; i++) {
        if (cb[position.x][i] == nullptr) {
        } else {
            if (cb[position.x][i]->getTeam() != getTeam())
                v.push_back(Point(position.x, i));
            break;
        }
    }
    for (Point vv : v) {
        if (!vv.NotVaild()) {
            w.push_back(vv);
        }
    }
    return w;
}

std::string Chariot::toString() {
    return getTeam() ? "d" : "D";
}

Cannon::Cannon(int team, Point pos) {
    this->team = team; position = pos;
}

std::vector<Point> Cannon::canMoveTo(Chess*** cb) {
    std::vector<Point> v, w;
    for (int i = position.x - 1; i > 1; i--) {
        if (cb[i][position.y] == nullptr) {
            v.push_back(Point(i, position.y));
        } else {
            break;
        }
    }
    for (int i = position.x + 1; i < 11; i++) {
        if (cb[i][position.y] == nullptr) {
            v.push_back(Point(i, position.y));
        } else {
            break;
        }
    }
    for (int i = position.y - 1; i > 1; i--) {
        if (cb[position.x][i] == nullptr) {
            v.push_back(Point(position.x, i));
        } else {
            break;
        }
    }
    for (int i = position.y + 1; i < 12; i++) {
        if (cb[position.x][i] == nullptr) {
            v.push_back(Point(position.x, i));
        } else {
            break;
        }
    }
    for (Point vv : v) {
        if (!vv.NotVaild()) {
            w.push_back(vv);
        }
    }
    return w;
}

std::vector<Point> Cannon::canAttackTo(Chess*** cb) {
    int count = 0;
    std::vector<Point> v, w;
    for (int i = position.x - 1; i > 1; i--) {
        if (cb[i][position.y] == nullptr) {
        } else {
            count++;
            if (count > 1) {
                if (cb[i][position.y]->getTeam() != getTeam())
                    v.push_back(Point(i, position.y));
                break;
            }
        }
    }
    count = 0;
    for (int i = position.x + 1; i < 11; i++) {
        if (cb[i][position.y] == nullptr) {
        } else {
            count++;
            if (count > 1) {
                if (cb[i][position.y]->getTeam() != getTeam())
                    v.push_back(Point(i, position.y));
                break;
            }
        }
    }
    count = 0;
    for (int i = position.y - 1; i > 1; i--) {
        if (cb[position.x][i] == nullptr) {
        } else {
            count++;
            if (count > 1) {
                if (cb[position.x][i]->getTeam() != getTeam())
                    v.push_back(Point(position.x, i));
                break;
            }
        }
    }
    count = 0;
    for (int i = position.y + 1; i < 12; i++) {
        if (cb[position.x][i] == nullptr) {
        } else {
            count++;
            if (count > 1) {
                if (cb[position.x][i]->getTeam() != getTeam())
                    v.push_back(Point(position.x, i));
                break;
            }
        }
    }
    for (Point vv : v) {
        if (!vv.NotVaild()) {
            w.push_back(vv);
        }
    }
    return w;
}

std::string Cannon::toString() {
    return getTeam() ? "b" : "B";
}

Soldier::Soldier(int team, Point pos) {
    this->team = team; position = pos;
}

std::vector<Point> Soldier::canMoveTo(Chess*** cb) {
    std::vector<Point> v, w;
    if (getTeam()) {
        if (cb[position.x][position.y - 1] == nullptr) {
            v.push_back(Point(position.x, position.y - 1));
        }
        if (position.y < 7) {
            if (cb[position.x - 1][position.y] == nullptr)
                v.push_back(Point(position.x - 1, position.y));
            if (cb[position.x + 1][position.y] == nullptr)
                v.push_back(Point(position.x + 1, position.y));
        }
    } else {
        if (cb[position.x][position.y + 1] == nullptr) {
            v.push_back(Point(position.x, position.y + 1));
        }
        if (position.y > 6) {
            if (cb[position.x - 1][position.y] == nullptr)
                v.push_back(Point(position.x - 1, position.y));
            if (cb[position.x + 1][position.y] == nullptr)
                v.push_back(Point(position.x + 1, position.y));
        }
    }
    for (Point vv : v) {
        if (!vv.NotVaild()) {
            w.push_back(vv);
        }
    }
    return w;
}

std::vector<Point> Soldier::canAttackTo(Chess*** cb) {
    std::vector<Point> v, w;
    if (getTeam()) {
        if (cb[position.x][position.y - 1] != nullptr) {
            v.push_back(Point(position.x, position.y - 1));
        }
        if (position.y < 7) {
            if (cb[position.x - 1][position.y] != nullptr)
                v.push_back(Point(position.x - 1, position.y));
            if (cb[position.x + 1][position.y] != nullptr)
                v.push_back(Point(position.x + 1, position.y));
        }
    } else {
        if (cb[position.x][position.y + 1] != nullptr) {
            v.push_back(Point(position.x, position.y + 1));
        }
        if (position.y > 6) {
            if (cb[position.x - 1][position.y] != nullptr)
                v.push_back(Point(position.x - 1, position.y));
            if (cb[position.x + 1][position.y] != nullptr)
                v.push_back(Point(position.x + 1, position.y));
        }
    }
    for (Point vv : v) {
        if (!vv.NotVaild() && cb[vv.x][vv.y]->getTeam() != getTeam()) {
            w.push_back(vv);
        }
    }
    return w;
}

std::string Soldier::toString() {
    return getTeam() ? "a" : "A";
}
