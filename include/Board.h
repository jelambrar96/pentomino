#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "Point.h"
#include "Shape.h"
#include "Figures.h"


class Board {
public:

    Board(int n, int m);
    Board(int n, int m, char * data);
    virtual ~Board();

    bool addShape(Shape s, int x, int y);
    bool removeShape(Shape s, int  x, int y);

    virtual std::vector<Shape> getShapes(int x, int y) = 0;

    bool isFully() { return _count == (_m * _n); }
    bool isEmpty() { return _count == _minimun; }

    static const int EMPTY_CHAR = '\0'; 

protected:

    int genertate_code(int x, int y);

    char *_board;
    int _m, _n;
    int _count;
    int _minimun;

};


class Board1 : public Board {
    virtual std::vector<Shape> getShapes(int x, int y);
};


class Board2 : public Board {
    virtual std::vector<Shape> getShapes(int x, int y);
};


#endif
