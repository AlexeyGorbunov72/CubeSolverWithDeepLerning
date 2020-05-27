#include <iostream>

#include "CubeSolver/CubeSolver.h"
#include "vector"
#include "Model/Model.h"
#include "string"
#include "iostream"
int main() {

    Cube test;
    Cube anus = anus.scrambleCube(8);


    anus.printCube(anus.theCubeData);
    std::cout << "- -- - - - - -  - - - - - - " << std::endl;

    CubeSolver solver;
    std::cout << "- -- - - - - -  - - - - - - " << std::endl;

    Cube answer = solver.solveTheCube(anus);
    answer.printCube(answer.theCubeData);
    for(string& suka: answer.getHistory()){
        std::cout << suka << std::endl;
    }

    return 0;
}