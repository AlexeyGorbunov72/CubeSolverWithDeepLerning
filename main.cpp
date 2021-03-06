#include <iostream>
#include "CubeSolver/CubeSolver.h"
#include "vector"
#include "Model/Model.h"
#include "string"
#include "iostream"

int main(int argc, char** argv) {

    Cube test;
    test = test.Fn();
    test = test.Rn();
    test = test.L();
    test = test.B();
    test.printCube(test.theCubeData);
    std::cout << "Source cube: " << std::endl;
    test.printCube(test.theCubeData);
    Cube toSend = test;
    vector<string> empty;
    toSend.setHistory(empty);
    CubeSolver solver;
    Cube answer = solver.solveTheCube(test);
    vector<string> history =  answer.getHistory();
    std::cout << "Moves to solve: " << std::endl;
    for(string& move: history){
        std::cout << move << std::endl;
    }
    std::cout << "Scrams cube: " << std::endl;
    //test.printHistory();
    return 0;
}