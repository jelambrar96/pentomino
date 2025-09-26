#include "PentoSolver.h"


AbsPentoSolver::AbsPentoSolver(char* _board, int _h , int _w, char* _shapes, int _num_shapes) 
    : h(_h), w(_w), num_shapes(_num_shapes) {
    
    const int nh = h + 4, nw = w + 4;
    
    board = new char[nh * nw];
    for (int i = 0; i < nh; ++i) {
        for (int j = 0; j < nw; ++j) {
            int ind = i * nw + j;
            if (i < 2 || j < 2) {
                board[ind] = PentoShapeFactory::USED;
            }
            else if (i >= (h + 2) || j >= (w + 2)) {
                board[ind] = PentoShapeFactory::USED;
            }
            else {
                int oind = (i - 2) * w + (j - 2);
                board[ind] = _board[oind];
            }
        }
    }
    
    shapes = _shapes;

}

AbsPentoSolver::~AbsPentoSolver() {
    delete [] board;
}


void AbsPentoSolver::displayBoard(char * board, int h, int w) {
    for (int i = 0; i <h ; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cout << board[i * w +  j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}


void AbsPentoSolver::displayIslands(int * board, int h, int w) {
    for (int i = 0; i <h ; ++i) {
        for (int j = 0; j < w; ++j) {
            std::cout << board[i * w +  j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}


void AbsPentoSolver::islandCounter(char *board, int* island, int h, int w) {
    
    bool *visited = new bool[h * w]; 
    for (int i = 0, n = h * w; i < n; ++i) {
        island[i] = -1;
        visited[i] = false;
    }

    for (int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            int ind = i * w + j;
            if (island[ind] >= 0) { continue; }
            if (board[ind] != PentoShapeFactory::EMPTY) { island[ind] = 0; continue; }
            int counter = islandCounterRec(board, visited, h, w, i, j, 0);
            islandGenerateRec(island, visited, h, w, i, j, counter);
        }
    }

    delete [] visited;
}


int AbsPentoSolver::islandCounterRec(char *board, bool * visited, int h, int w, int i, int j, int deep) {
    
    if (i < 0 || i >= h) { return 0; }
    if (j < 0 || j >= w) { return 0; }
    
    int ind = i * w + j;

    if (board[ind] != PentoShapeFactory::EMPTY) { return 0; }
    if (visited[ind]) { return 0; }
    
    visited[ind] = true;
    deep += 1;

    deep += islandCounterRec(board, visited, h, w, i, j - 1, 0); // up
    deep += islandCounterRec(board, visited, h, w, i, j + 1, 0); // down
    deep += islandCounterRec(board, visited, h, w, i - 1, j, 0); // left
    deep += islandCounterRec(board, visited, h, w, i + 1, j, 0); // right
    
    return deep;
}


void AbsPentoSolver::islandGenerateRec(int * island, bool * visited, int h, int w, int i, int j, int value) {
    if (i < 0 || i >= h) { return; }
    if (j < 0 || j >= w) { return; }

    int ind = i * w + j;
    if (island[ind] >= 0) { return; }
    if (!visited[ind]) { return; }

    island[ind] = value;
    islandGenerateRec(island, visited, h, w, i, j - 1, value); // up
    islandGenerateRec(island, visited, h, w, i, j + 1, value); // down
    islandGenerateRec(island, visited, h, w, i - 1, j, value); // left
    islandGenerateRec(island, visited, h, w, i + 1, j, value); // right
}

// ----------------------------------------------------------------------------------------------------------------


PentoSolver::PentoSolver(char* _board, int _h , int _w, char* _shapes, int _num_shapes) 
    : AbsPentoSolver(_board, _h, _w, _shapes, _num_shapes) {}

PentoSolver::~PentoSolver() {}


void PentoSolver::solve() {

    this->recusiveSolver(0);
}


bool PentoSolver::recusiveSolver(int ind) {

    // this->displayBoard(board, h + 4, w + 4);

    if (ind >= num_shapes) {
        std::cout << "solution found" << std::endl;
        displayBoard(board, h + 4, w + 4);
        return true;
    }

    // std::cout << ind << std::endl;
    // displayBoard(board, h + 4, w + 4);

    int * islas = new int[(h + 4)* (w + 4)];
    islandCounter(board, islas, h + 4, w + 4);
    bool valid = true;
    for (int i = 0 , n = (h + 4)* (w + 4);  i < n; ++i) {
        if (islas[i] % 5 > 0) {
            valid = false;
            break;
        }
    }

    // displayBoard(board, h, w);
    // displayBoard(islas, h + 4, w + 4);
    // std::cout << "\n";

    delete [] islas;
    if (!valid) { return false; }
    // 

    char current_shape = shapes[ind];
    int number_of_position_shape = PentoShapeFactory::getNUmbers(current_shape);
    int position_shape = PentoShapeFactory::getShapes(current_shape);

    // std::cout << ind << " variant shape " << current_shape << std::endl;
    
    // para cada una de las posiciones del tablero
    for (int i = 2, ilimit = h + 2; i < ilimit; ++i) {
        for (int j = 2, jlimit = w + 2; j < jlimit; ++j) {

            // para cada variabte de la pieza
            for (int k = 0; k < number_of_position_shape; ++k) {
                int indk = position_shape + k;
                
                // se lee la pieza
                char shape[5][5];
                for (int i2 = 0; i2 < 5; ++i2) {
                    for (int j2 = 0; j2 < 5; ++j2) {
                        shape[i2][j2] = PentoShapeFactory::SHAPES[indk][i2][j2];
                    }
                }
        
                // std::cout << i << ", " << j << std::endl;
            
                // se eliminan las posiciones ocupadas
                int indb = i * (w + 4) + j;
                if (board[indb] != PentoShapeFactory::EMPTY) { continue; }

                // std::cout << "free space" << std::endl;

                // se verifica si la pieza encaja
                bool check = true;
                for (int i2 = 0; i2 < 5 && check; ++i2) {
                    for (int j2 = 0; j2 < 5 && check; ++j2) {
                        if (shape[i2][j2] == PentoShapeFactory::EMPTY) { continue; }
                        int newind = (i + i2 - 2) * (w + 4) + (j + j2 - 2);
                        if (board[newind] != PentoShapeFactory::EMPTY) {
                            check = false;
                        }
                    }
                }
                // std::cout << "check " << check << " in position " << i << ", " << j << std::endl;
                // si la variante no encaja se intenta con la sigueinte.
                if (!check) { continue; }

                // si la variante encaja se agrega a la pieza
                for (int i2 = 0; i2 < 5 && check; ++i2) {
                    for (int j2 = 0; j2 < 5 && check; ++j2) {
                        if (shape[i2][j2] == PentoShapeFactory::EMPTY) { continue; }
                        int newind = (i + i2 - 2) * (w + 4) + (j + j2 - 2);
                        // board[newind] = PentoShapeFactory::USED;
                        board[newind] = current_shape;
                    }
                }

                // se llama la la funcion con un indice mayor
                this-> recusiveSolver(ind + 1);

                // se quita la variante de la pieza
                for (int i2 = 0; i2 < 5 && check; ++i2) {
                    for (int j2 = 0; j2 < 5 && check; ++j2) {
                        if (shape[i2][j2] == PentoShapeFactory::EMPTY) { continue; }
                        int newind = (i + i2 - 2) * (w + 4) + (j + j2 - 2);
                        board[newind] = PentoShapeFactory::EMPTY;
                    }
                }


            }
        }

    }


    return false;
};

// ------------------------------------------------------------------------------------------------------------------------


KPentoSolver::KPentoSolver(char* _board, int _h , int _w, char* _shapes, int _num_shapes) 
    : AbsPentoSolver(_board, _h, _w, _shapes, _num_shapes) {

    // vector of shapes
    vector_shapes = std::vector<char>(_num_shapes);
    for (int i = 0; i < _num_shapes; ++i) { vector_shapes.push_back(_shapes[i]); }
        
    // tree
    tree = std::vector<std::vector<int>>(25);
    for (int i = 0; i < 25; ++i) { tree.push_back(std::vector<int>()); }

    for (int k = 0; k < 63; ++k) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                char c = PentoShapeFactory::SHAPES[k][i][j];
                if (c == PentoShapeFactory::EMPTY) { continue; }
                char shape_char = PentoShapeFactory::CHAR_SHAPES[k];
                
                // DONE: add optimation if shape_char in _shapes
                bool found = false;
                for (int l = 0; i < _num_shapes; ++l) {
                    if (_shapes[l] == shape_char) { found = true; break; }
                }
                if (!found) { continue; }
                
                int ind = i * 5 + j;
                tree.at(ind).push_back(k);
            }
        }
    }
}


KPentoSolver::~KPentoSolver() {}


void KPentoSolver::solve() {
    recusiveSolver();
}


bool KPentoSolver::recusiveSolver() {
    
    if (vector_shapes.empty()) {
        std::cout << "solution found" << std::endl;
        return true;
    }

    // std::cout << ind << std::endl;
    // displayBoard(board, h + 4, w + 4);

    int * islas = new int[(h + 4)* (w + 4)];
    islandCounter(board, islas, h + 4, w + 4);
    bool valid = true;
    for (int i = 0 , n = (h + 4)* (w + 4);  i < n; ++i) {
        if (islas[i] % 5 > 0) {
            valid = false;
            break;
        }
    }

    // displayBoard(board, h, w);
    // displayBoard(islas, h + 4, w + 4);
    // std::cout << "\n";

    delete [] islas;
    if (!valid) { return false; }
    // 


    // para cada una de las posiciones del tablero
    for (int i = 2, ilimit = h + 2; i < ilimit; ++i) {
        for (int j = 2, jlimit = w + 2; j < jlimit; ++j) {

            std::vector<char> copy_vector_shape = vector_shapes;

            // 
            for (int i2 = 0; i2 < 5; ++i2) {
                for (int j2 = 0; j2 < 5; ++j2) {
                    
                }
            }

        }
    }

    throw;
}
