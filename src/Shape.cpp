#include "Shape.hpp"


Shape::Shape(char _type, Point *_points, Point _position) {
    //ctor
    type = _type;
    // points = new Point[N_POINTS];
    for (int i=0; i < N_POINTS; ++i) {
        points[i] = Point(_points[i].x, _points[i].y);
    }
    position = _position;
}


Shape::~Shape() {
    //dtor
    // if (points != nullptr) { delete [] points };
    //  delete [] points;
    // points = nullptr; 
    // std::cout << "dtor\n";
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


// Shape ShapeFactory::arrayShapes[1] = {
//     Shape::Shape('x', { Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 0)})
// };

