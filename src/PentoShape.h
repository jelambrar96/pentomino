#ifndef PENTOSHAPE_H
#define PENTOSHAPE_H

#include <iostream>

class PentoShapeFactory {
public:
    static const char EMPTY = ' ';
    static const char USED  = '#';

    static const char SHAPES[63][5][5]; 
    static const char CHAR_SHAPES[63];

    static int getShapes(char c);
    static int getNUmbers(char c);

    static void displayShapes();


private:
};



#endif