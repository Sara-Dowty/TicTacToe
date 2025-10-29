//
// Created by dowty on 6/6/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Mark.h"


class Player {
public:
    Player();

    void assignMark(Mark mark);
    Mark getMark();

private:
    Mark mark;
};

#endif //PLAYER_H
