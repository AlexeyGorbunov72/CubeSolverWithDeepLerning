#include <iostream>

#include "CubeSolver/CubeSolver.h"
#include "vector"
#include "Model/Model.h"
#include "string"
#include "iostream"
int main() {

    Cube test;
    Cube anus = test.U();
    Cube ochko = anus.L();
    Cube ochko2 = ochko.D();
    ochko.printCube(ochko2.theCubeData);
    CubeSolver solver;
    std::cout << "- -- - - - - -  - - - - - - ";

    Cube answer = solver.solveTheCube(ochko2);
    answer.printCube(answer.theCubeData);
    for(string& suka: answer.getHistory()){
        std::cout << suka << std::endl;
    }
}