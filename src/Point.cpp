#include "Point.h"

Point::Point(int _x, int _y): x(_x), y(_y)
{
    //ctor
}

Point::Point(const Point &p2): x(p2.x), y(p2.y)
{
    //ctor
}

Point::~Point()
{
    //dtor
}

std::ostream& operator<<(std::ostream &strm, const Point &p) {
  return strm << "P(" <<  p.x << ", " << p.y << ")";
}
