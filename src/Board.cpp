#include "Board.h"


Board::Board(int n, int m) {
    _board = new char[n * m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            _board[i * n + j] = EMPTY_CHAR;
        }
    }
    _m = m;
    _n = n;
    _minimun = 0;
}


Board::Board(int n, int m, char * data) {
    _board = new char[n * m];
    _m = m;
    _n = n;
    int mn = m * n;
    for (int i = 0; i < mn; ++i) {
        _board[i] = data[i];
        if (_board[i] != EMPTY_CHAR) {
            _count++;
        }
    }
    _minimun = _count++;
}


Board::~Board() {
    delete _board;
}

bool Board::addShape(Shape s, int x, int y) {
    std::vector<Point> new_points;
    bool flag = true;
    for (Point p: s.points) {
        int _x = x + p.x;
        int _y = y + p.y;
        if (_x < 0) {
            flag = false;
        }
        if (_x >= _m) {
            flag = false;
        }
        if (_y < 0) {
            flag = false;
        }
        if (_y >= _n) {
            flag = false;
        }
        if (!flag) { break; }
        new_points.push_back(Point(x, y));
    }
    if (!flag) {
        return false;
    }
    for (Point p: new_points) {
        _board[p.y * _n + p.x] = s.type;
    }
    return true;
}

bool Board::removeShape(Shape s, int  x, int y) {
    std::vector<Point> new_points;
    bool flag = true;
    for (Point p: s.points) {
        int _x = x + p.x;
        int _y = y + p.y;
        if (_x < 0) {
            flag = false;
        }
        if (_x >= _m) {
            flag = false;
        }
        if (_y < 0) {
            flag = false;
        }
        if (_y >= _n) {
            flag = false;
        }
        if (!flag) { break; }
        new_points.push_back(Point(x, y));
    }
    if (!flag) {
        return false;
    }
    for (Point p: new_points) {
        _board[p.y * _n + p.x] = EMPTY_CHAR;
    }
    return true;
}

// ----------------------------------------------------------------------------
std::vector<Shape> Board1::getShapes (int x, int y) {
    std::vector<Shape> shapes = {};
    if (_board[x*_n + y] != EMPTY_CHAR) {
        return  shapes;
    }
    for (Shape s: Figures::all_figures) {
        bool flag = true;
        int mn = _m * _n;
        for (int i = 1; i < 5; ++i) {
            int ind = (y + s.points[i].y) * _n + (x + s.points[i].x);
            if (ind < 0) { 
                flag = false;
                break;
            }
            if (ind > mn) {
                flag = false;
                break;
            }
            if (_board[ind] != EMPTY_CHAR) {
                flag = false;
                break;
            }
        }
        if (flag) {
            shapes.push_back(s);
        }
    }
    return shapes;
}

int Board::genertate_code(int x, int y) {
    int board_code = 0;
    int cont = 0;
    y -= 2;
    x -= 2;
    for (int i = y; i < y + 5; ++i) {
        for (int j = x; j < y + 5; ++j) {
            int temp = 0;
            if (i < 0) {
                temp = 1;
            }
            else if (_n <= i) {
                temp = 1;
            }
            else if (j < 0) {
                temp = 1;
            }
            else if (_m <= j) {
                temp = 1;
            }
            else {
                temp = _board[_n * i + j] == EMPTY_CHAR ? 0 : 1;
            }
            temp <<= cont++;
            board_code |= temp;
        }
    }
    return board_code;
}


// ----------------------------------------------------------------------------
std::vector<Shape> Board2::getShapes (int x, int y) {
    std::vector<Shape> shapes = {};
    if (_board[x*_n + y] != EMPTY_CHAR) {
        return  shapes;
    }
    int board_code = this->genertate_code(x, y);
    for (Shape s: Figures::all_figures) {
        int output = board_code & s.code;
        if (output == 0) {
            shapes.push_back(s);
        }
    }
    return shapes;
}
