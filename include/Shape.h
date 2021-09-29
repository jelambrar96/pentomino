#ifndef SHAPE_H
#define SHAPE_H

#define N_POINTS 5

#include <ostream>
#include <vector>
#include <iostream>
#include <bitset>

#include "Point.h"

class Shape
{
    public:
        Shape(char c, Point *p);
        Shape(char c, std::initializer_list<Point> plist);
        virtual ~Shape();

        Point points[5];
        char type;
        void display();
        int code;

    protected:

    private:
        static void display_shape(Shape *s);
};

std::ostream& operator<<(std::ostream &strm, const Shape &s);

#endif // SHAPE_H
