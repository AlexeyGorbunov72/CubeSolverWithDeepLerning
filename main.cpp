#include <iostream>
#include "Model/Model.h"
#include <iomanip>
#include <map>
#include "CubeSolver/CubeSolver.h"
#include "Cube/Cube.h"
int main() {
    Cube cube;

    CubeSolver cubeSolver;
    cubeSolver.solveTheCube(cube);
    return 0;
}