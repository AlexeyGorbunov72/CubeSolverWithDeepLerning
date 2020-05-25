#include <iostream>

#include "Model/Model.h"
#include <iomanip>
#include <map>
#include "CubeSolver/CubeSolver.h"
#include "Cube/Cube.h"
#include "Cube/CubeRotationSupportForStupidMe.h"
#include "string"
int main() {

    std::string cube[6][3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j != 0)
                cube[0][i][j] = "green";
            else
                cube[0][i][j] = "yellow";
            
        }
    }

    CubeRotationSupportForStupidMe hui(cube, 0);
    std::string* buffer = hui.getRightPartOfSide();
    for(int i = 0; i < 3; i++){
        std::cout << buffer[i] << std::endl;
    }
    return 0;

}