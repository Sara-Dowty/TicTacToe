//
// Created by dowty on 6/2/2025.
//

#include "Square.h"

#include <stdexcept>
#include <string>

using namespace std;

Square::Square() {;
}

Mark Square::get_mark() const {
    if (this->is_empty()) {
        const string message = "Square is empty";
        throw runtime_error(message);
    } return this->mark;
}
void Square::set_mark(const Mark &new_mark) {
    if (this->is_empty()) {
        this->mark = new_mark;
        this->isEmpty = false;
    } else {
        const string message = "Square is already marked.";
        throw runtime_error(message);
    }
}




