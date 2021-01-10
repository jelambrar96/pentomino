#ifndef FIGURES_H
#define FIGURES_H

#include "Shape.h"


namespace Figures{

    // enum VALID_VALUES: char {X = 'x', };

    const Shape X0 = Shape('x', {Point(0, 0), Point(-1, 0), Point(1, 0), Point(0, 1), Point(0, -1)});

    const Shape I0 = Shape('i', {Point(0, 0), Point(-1, 0), Point(-2, 0), Point(1, 0), Point(2, 0)});
    const Shape I1 = Shape('i', {Point(0, 0), Point(0, -1), Point(0, -2), Point(0, 1), Point(0, 2)});

    const Shape Z0 = Shape('z', {Point(0, 0), Point(-1, -1), Point(0, -1), Point(0, 1), Point(1, 1)});
    const Shape Z1 = Shape('z', {Point(0, 0), Point(1, -1), Point(0, -1), Point(0, 1), Point(-1, 1)});
    const Shape Z2 = Shape('z', {Point(0, 0), Point(-1, 1), Point(-1, 0), Point(1, 0), Point(1, -1)});
    const Shape Z3 = Shape('z', {Point(0, 0), Point(1, 1), Point(-1, 0), Point(1, 0), Point(-1, -1)});

    const Shape V0 = Shape('v', {Point(0, 0), Point(1, 0), Point(2, 0), Point(0, 1), Point(0, 2)});
    const Shape V1 = Shape('v', {Point(0, 0), Point(-1, 0), Point(-2, 0), Point(0, 1), Point(0, 2)});
    const Shape V2 = Shape('v', {Point(0, 0), Point(1, 0), Point(2, 0), Point(0, -1), Point(0, -2)});
    const Shape V3 = Shape('v', {Point(0, 0), Point(-1, 0), Point(-2, 0), Point(0, -1), Point(0, -2)});

    const Shape W0 = Shape('w', {Point(0, 0), Point(-1, 0), Point(0, 1), Point(-1, -1), Point(1, 1)});
    const Shape W1 = Shape('w', {Point(0, 0), Point(0, -1), Point(1, 0), Point(-1, -1), Point(1, 1)});
    const Shape W2 = Shape('w', {Point(0, 0), Point(0, 1), Point(1, 0), Point(-1, 1), Point(1, -1)});
    const Shape W3 = Shape('w', {Point(0, 0), Point(0, -1), Point(-1, 0), Point(-1, 1), Point(1, -1)});

    const Shape T0 = Shape('t', {Point(0, 0), Point(1, 0), Point(2, 0), Point(2, -1), Point(2, 1)});
    const Shape T1 = Shape('t', {Point(0, 0), Point(-1, 0), Point(-2, 0), Point(-2, -1), Point(-2, 1)});
    const Shape T2 = Shape('t', {Point(0, 0), Point(0, 1), Point(0, 2), Point(1, 2), Point(-1, 2)});
    const Shape T3 = Shape('t', {Point(0, 0), Point(0, -1), Point(0, -2), Point(1, -2), Point(-1, -2)});
    
    const Shape U0 = Shape('u', {Point(0, 0), Point(1, 0), Point(-1, 0), Point(1, 1), Point(-1, 1)});
    const Shape U1 = Shape('u', {Point(0, 0), Point(1, 0), Point(-1, 0), Point(1, -1), Point(-1, -1)});
    const Shape U2 = Shape('u', {Point(0, 0), Point(0, 1), Point(0, -1), Point(1, -1), Point(1, 1)});
    const Shape U3 = Shape('u', {Point(0, 0), Point(0, 1), Point(0, -1), Point(-1, -1), Point(-1, 1)});

    const Shape F0 = Shape('f', {Point(0, 0), Point(-1, 0), Point(1, 0), Point(0, -1), Point(1, 1)});
    const Shape F1 = Shape('f', {Point(0, 0), Point(-1, 0), Point(1, 0), Point(0, -1), Point(-1, 1)});
    const Shape F2 = Shape('f', {Point(0, 0), Point(-1, 0), Point(1, 0), Point(0, 1), Point(-1, -1)});
    const Shape F3 = Shape('f', {Point(0, 0), Point(-1, 0), Point(1, 0), Point(0, 1), Point(1, -1)});
    const Shape F4 = Shape('f', {Point(0, 0), Point(0, -1), Point(0, 1), Point(1, 0), Point(-1, -1)});
    const Shape F5 = Shape('f', {Point(0, 0), Point(0, -1), Point(0, 1), Point(1, 0), Point(-1, 1)});
    const Shape F6 = Shape('f', {Point(0, 0), Point(0, -1), Point(0, 1), Point(-1, 0), Point(1, 1)});
    const Shape F7 = Shape('f', {Point(0, 0), Point(0, -1), Point(0, 1), Point(-1, 0), Point(1, -1)});

    const Shape L0 = Shape('l', {Point(0, 0), Point(-2, 0), Point(-1, 0), Point(1, 0), Point(1, 1)});
    const Shape L1 = Shape('l', {Point(0, 0), Point(-2, 0), Point(-1, 0), Point(1, 0), Point(1, -1)});
    const Shape L2 = Shape('l', {Point(0, 0), Point(2, 0), Point(1, 0), Point(-1, 0), Point(-1, 1)});
    const Shape L3 = Shape('l', {Point(0, 0), Point(2, 0), Point(1, 0), Point(-1, 0), Point(-1, -1)});
    const Shape L4 = Shape('l', {Point(0, 0), Point(0, 2), Point(0, 1), Point(0, -1), Point(1, -1)});
    const Shape L5 = Shape('l', {Point(0, 0), Point(0, 2), Point(0, 1), Point(0, -1), Point(-1, -1)});
    const Shape L6 = Shape('l', {Point(0, 0), Point(0, -2), Point(0, -1), Point(0, 1), Point(1, 1)});
    const Shape L7 = Shape('l', {Point(0, 0), Point(0, -2), Point(0, -1), Point(0, 1), Point(-1, 1)});

    const Shape N0 = Shape('n', {Point(0, 0), Point(0, 1), Point(0, 2), Point(-1, 0), Point(-1, -1)});
    const Shape N1 = Shape('n', {Point(0, 0), Point(0, 1), Point(0, 2), Point(1, 0), Point(1, -1)});
    const Shape N2 = Shape('n', {Point(0, 0), Point(0, -1), Point(0, -2), Point(-1, 0), Point(-1, 1)});
    const Shape N3 = Shape('n', {Point(0, 0), Point(0, -1), Point(0, -2), Point(1, 0), Point(1, 1)});
    const Shape N4 = Shape('n', {Point(0, 0), Point(1, 0), Point(2, 0), Point(0, 1), Point(-1, 1)});
    const Shape N5 = Shape('n', {Point(0, 0), Point(1, 0), Point(2, 0), Point(0, -1), Point(-1, -1)});
    const Shape N6 = Shape('n', {Point(0, 0), Point(-1, 0), Point(-2, 0), Point(0, 1), Point(1, 1)});
    const Shape N7 = Shape('n', {Point(0, 0), Point(-1, 0), Point(-2, 0), Point(0, -1), Point(1, -1)});

    const Shape P0 = Shape('p', {Point(0, 0), Point(-1, 0), Point(1, 0), Point(0, 1), Point(1, 1)});
    const Shape P1 = Shape('p', {Point(0, 0), Point(-1, 0), Point(1, 0), Point(0, 1), Point(-1, 1)});
    const Shape P2 = Shape('p', {Point(0, 0), Point(-1, 0), Point(1, 0), Point(0, -1), Point(1, -1)});
    const Shape P3 = Shape('p', {Point(0, 0), Point(-1, 0), Point(1, 0), Point(0, -1), Point(-1, -1)});
    const Shape P4 = Shape('p', {Point(0, 0), Point(0, -1), Point(0, 1), Point(1, 0), Point(1, 1)});
    const Shape P5 = Shape('p', {Point(0, 0), Point(0, -1), Point(0, 1), Point(1, 0), Point(1, -1)});
    const Shape P6 = Shape('p', {Point(0, 0), Point(0, -1), Point(0, 1), Point(-1, 0), Point(-1, 1)});
    const Shape P7 = Shape('p', {Point(0, 0), Point(0, -1), Point(0, 1), Point(-1, 0), Point(-1, -1)});

    const Shape Y0 = Shape('y', {Point(0, 0), Point(-2, 0), Point(-1, 0), Point(1, 0), Point(0, 1)});
    const Shape Y1 = Shape('y', {Point(0, 0), Point(-2, 0), Point(-1, 0), Point(1, 0), Point(0, -1)});
    const Shape Y2 = Shape('y', {Point(0, 0), Point(2, 0), Point(1, 0), Point(-1, 0), Point(0, 1)});
    const Shape Y3 = Shape('y', {Point(0, 0), Point(2, 0), Point(1, 0), Point(-1, 0), Point(0, -1)});
    const Shape Y4 = Shape('y', {Point(0, 0), Point(0, 2), Point(0, 1), Point(0, -1), Point(1, 0)});
    const Shape Y5 = Shape('y', {Point(0, 0), Point(0, 2), Point(0, 1), Point(0, -1), Point(-1, 0)});
    const Shape Y6 = Shape('y', {Point(0, 0), Point(0, -2), Point(0, -1), Point(0, 1), Point(1, 0)});
    const Shape Y7 = Shape('y', {Point(0, 0), Point(0, -2), Point(0, -1), Point(0, 1), Point(-1, 0)});

    const std::vector<Shape> all_figures = { X0, I0, I1, Z0, Z1, Z2, Z3,
        V0, V1, V2, V3, W0, W1, W2, W3, T0, T1, T2, T3, U0, U1, U2, U3, F0, F1, F2, F3, F4, F5, F6, F7,
        L0, L1, L2, L3, L4, L5, L6, L7, N0, N1, N2, N3, N4, N5, N6, N7, P0, P1, P2, P3, P4, P5, P6, P7,
        Y0, Y1, Y2, Y3, Y4, Y5, Y6, Y7
    };
};

#endif // FIGURES_H
