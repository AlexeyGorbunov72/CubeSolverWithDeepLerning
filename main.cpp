#include <iostream>

#include "Model/Model.h"
#include <iomanip>
#include <map>
#include "CubeSolver/CubeSolver.h"
#include "Cube/Cube.h"
#include "Cube/CubeRotationSupportForStupidMe.h"
#include "string"
int main() {

    vector<int > suka;
    suka.push_back(1488);
    for(int & ochko : suka){
        suka.push_back(2);
    }
    std::cout << suka.size();
    return 0;

}