#ifndef PENTO_SOLVER_H
#define PENTO_SOLVER_H

#include <vector>
#include <iostream>


#include "PentoShape.h"


class PentoSolver {
public:
    PentoSolver(char* _board, int _h , int _w, char* _shapes, int _num_shapes);
    ~PentoSolver();
    void solve();
    
    // std::vector<PentoSolution> getSolutions();
private:
    char * board;
    char * shapes;
    const int h;
    const int w; 
    const int num_shapes;

    bool recusiveSolver(int ind);

    void islandCounter(char *board, int* island, int h, int w);
    int islandCounterRec(char *board, bool *visited, int h, int w, int i, int j, int deep);
    void  islandGenerateRec(int *island, bool *visited, int h, int w, int i, int j, int deep);
    
    void displayBoard(char *, int h, int w);
    void displayBoard(int *, int h, int w);
};





#endif
