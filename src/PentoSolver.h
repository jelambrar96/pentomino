#ifndef PENTO_SOLVER_H
#define PENTO_SOLVER_H

#include <vector>
#include <iostream>


#include "PentoShape.h"


class AbsPentoSolver {
public:
    AbsPentoSolver(char* _board, int _h , int _w, char* _shapes, int _num_shapes);
    ~AbsPentoSolver();
    virtual void solve() = 0;

    void displayBoard(char *, int h, int w);
    void displayIslands(int *, int h, int w);

    void islandCounter(char *board, int* island, int h, int w);
    int islandCounterRec(char *board, bool *visited, int h, int w, int i, int j, int deep);
    void  islandGenerateRec(int *island, bool *visited, int h, int w, int i, int j, int deep);

protected:
    char * board;
    char * shapes;
    const int h;
    const int w; 
    const int num_shapes;
};


class PentoSolver : public AbsPentoSolver {
public:
    PentoSolver(char* _board, int _h , int _w, char* _shapes, int _num_shapes);
    ~PentoSolver();
    virtual void solve();
    
    // std::vector<PentoSolution> getSolutions();
private:
    bool recusiveSolver(int ind);
};


class KPentoSolver : public AbsPentoSolver {
public:
    KPentoSolver(char* _board, int _h , int _w, char* _shapes, int _num_shapes);
    ~KPentoSolver();
    virtual void solve();
private:

    std::vector<std::vector<char>> tree;
    std::vector<char> vector_shapes;
    bool recusiveSolver();

};


#endif
