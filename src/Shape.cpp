#include "Shape.h"


Shape::Shape(char _type, Point *_points)
{
    //ctor
    type = _type;
    // points = new Point[N_POINTS];
    for (int i=0; i < N_POINTS; ++i) { points[i] = Point(_points[i]); }
    code = 0x00000000;
    for (int i=0; i < N_POINTS; ++i) {
        // get x and y
        int x = points[i].x + 2;
        int y = points[i].y + 2;
        // get number of rotations
        int ind = y * 5 + x;
        int temp = 1;
        temp <<= ind;
        code |= temp;
    }
}


Shape::Shape(char _type, std::initializer_list<Point> _points)
{
    //ctor
    type = _type;
    // points = new Point[N_POINTS];

    std::vector<Point> v;
    v.insert(v.begin(), _points.begin(), _points.end());
    for (int i=0; i < N_POINTS; ++i) { points[i] = Point(v[i]); }
    code = 0x00000000;
    for (int i=0; i < N_POINTS; ++i) {
        // get x and y
        int x = points[i].x + 2;
        int y = points[i].y + 2;
        // get number of rotations
        int ind = y * 5 + x;
        int temp = 1;
        temp <<= ind;
        code |= temp;
    }
}


Shape::~Shape()
{
    //dtor
    // if (points != nullptr) { delete [] points };
    //  delete [] points;
    // points = nullptr; 
    // std::cout << "dtor\n";
}


std::ostream& operator<<(std::ostream &strm, const Shape &s) {
    std::bitset<32> x(s.code);
    return strm << "Shape " << s.type << "\nPoints:\n"
        << s.points[0] << "\n"
        << s.points[1] << "\n"
        << s.points[2] << "\n"
        << s.points[3] << "\n"
        << s.points[4] << "\n"
        << "code: " << s.code << " "
        << x << "\n";
;
}


void Shape::display_shape(Shape *s) {
    char single_board[N_POINTS][N_POINTS];
    for (int i = 0; i < N_POINTS; ++i) {
        for (int j = 0; j < N_POINTS; ++j) {
            single_board[i][j] = ' ';
        }
    }
    for (int i = 0; i < N_POINTS; ++i) {
        int x = 2 + s->points[i].x;
        int y = 2 + s->points[i].y;
        single_board[y][x] = '#'; 
    }
    for (int i = 0; i < N_POINTS; ++i) {
        for (int j = 0; j < N_POINTS; ++j) {
            std::cout << single_board[i][j];
        }
        std::cout << "\n";
    }
}

void Shape::display() {
    Shape::display_shape(this);
}
