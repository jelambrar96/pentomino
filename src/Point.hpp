#ifndef POINT_HPP
#define POINT_HPP


class Point {
public:
    int x, y;
    Point();
    Point(int _x, int _y);
    Point& operator=(const Point& p);
};

#endif
