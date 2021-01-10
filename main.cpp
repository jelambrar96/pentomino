#include <iostream>


#include "Figures.h"

using namespace std;

int main()
{

	std::vector<Shape> shapes = Figures::all_figures;

	for (size_t i = 0; i < shapes.size(); ++i) {
	    Shape temp_shape(shapes[i]);
	    std::cout << temp_shape;
	    temp_shape.display();
	    std::cout << "\n";
	}
    
    return 0;
}
