#ifndef POINT_H
#define POINT_H

#include <ostream>

class Point
{
    public:
        Point(int x = 0, int y = 0);
        Point(const Point &p2);
        virtual ~Point();

        int x;
        int y;

    protected:

    private:
};

std::ostream& operator<<(std::ostream &strm, const Point &p);

#endif // POINT_H
