
#include "PentoShape.h"
#include "PentoSolver.h"

int main() {


    // PentoShapeFactory::displayShapes();

    // return 0;

    int h = 4;
    int w = 15;
    int n_shapes = 12;
    char shapes[n_shapes] = {'X', 'I', 'Z', 'V', 'W', 'T', 'U', 'N', 'F', 'L', 'Y', 'P'};

    // int h = 3;
    // int w = 10;
    // int n_shapes = 6;
    // char shapes[12] = {'X', 'I', 'U', 'N', 'Y', 'P'};

    char *board = new char[h * w];
    for (int i = 0, n = h * w; i < n; ++i){
        board[i] = ' ';
    } 

    PentoSolver psolver(board, h, w, shapes, n_shapes);
    psolver.solve();

    return 0;
}
