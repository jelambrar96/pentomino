#include "Point.hpp"

Point::Point() {
    x = 0, y = 0;
} 


Point::Point(int _x, int _y) {
    x = _x, y = _y;
}


Point& Point::operator=(const Point& other) {
    x = other.x;
    y = other.y;
    return *this;
}
