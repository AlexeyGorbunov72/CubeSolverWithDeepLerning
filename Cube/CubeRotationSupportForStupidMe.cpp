//
// Created by Alexey on 25.05.2020.
//

#include "CubeRotationSupportForStupidMe.h"

std::string* CubeRotationSupportForStupidMe::getBottomPartOfSide() {
    return side[2];
}

std::string* CubeRotationSupportForStupidMe::getTopPartOfSide() {
   return side[0];
}

std::string* CubeRotationSupportForStupidMe::getLeftPartOfSide() {
    std::string* line = new std::string[3];
    line[0] = side[0][0];
    line[1] = side[1][0];
    line[2] = side[2][0];
    return line;
}

std::string* CubeRotationSupportForStupidMe::getRightPartOfSide() {
    std::string* line = new std::string[3];
    line[0] = side[0][2];
    line[1] = side[1][2];
    line[2] = side[2][2];
    return line;
}

CubeRotationSupportForStupidMe::CubeRotationSupportForStupidMe(std::string cube[6][3][3], int index) {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            side[i][j] = cube[index][i][j];
        }
    }
}
