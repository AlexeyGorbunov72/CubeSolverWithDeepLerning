#include <iostream>
#include "Model.h"
#include <iomanip>
#include <map>
#include "CubeSolver.h"
#include "Cube.h"
int main() {
    Cube cube;

    CubeSolver cubeSolver;
    cubeSolver.solveTheCube(cube);
    return 0;
}