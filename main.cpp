#include <iostream>

#include "CubeSolver/CubeSolver.h"
#include "vector"
#include "Model/Model.h"
#include "string"
#include "iostream"
int main() {

    Cube testCube;
    testCube = testCube.Rn();
    CubeSolver solver;
    std::vector<std::string> result = solver.solveTheCube(testCube);
    for(string & move : result){
        std::cout << move << std::endl;
    }
    return 0;

}