//
// Created by dowty on 6/6/2025.
//

#include "Player.h"
//default constructor
Player::Player() : mark(Mark::X) {
    //default
}
//mutator
void Player::assignMark(Mark mark) {
    this->mark = mark;
}
//accessor
Mark Player::getMark() {
    return mark;
}

