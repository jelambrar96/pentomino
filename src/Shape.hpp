#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <vector>
#include <bitset>
#include <initializer_list>

#include "Point.hpp"


class Shape {
public:
    static const int N_POINTS = 5;

    Shape(char _type, Point* _points, Point position);
    ~Shape();

    void display();
    static void display_shape(Shape* s);

    char type;
    Point points[N_POINTS];
    Point position;

};


#endif // SHAPE_H