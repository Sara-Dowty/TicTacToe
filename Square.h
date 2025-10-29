//
// Created by dowty on 6/2/2025.
//

#ifndef SQUARE_H
#define SQUARE_H
#include "Mark.h"


class Square {
public:
    Square();
    [[nodiscard]] Mark get_mark() const;
    bool is_empty() const {return isEmpty;};
    void set_mark(const Mark &new_mark);

private:
    bool isEmpty {true};
    Mark mark{Mark::X};
};



#endif //SQUARE_H
