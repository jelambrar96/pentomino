#ifndef PENTOSHAPE_H
#define PENTOSHAPE_H


class PentoShapeFactory {
public:
    static const char EMPTY = ' ';
    static const char USED  = '#';

    static const char SHAPES[63][5][5]; 

    static int getShapes(char c);
    static int getNUmbers(char c);

private:
};



#endif