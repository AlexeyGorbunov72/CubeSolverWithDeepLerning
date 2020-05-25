//
// Created by Alexey on 25.05.2020.
//

#include "CubeRotationSupportForStupidMe.h"

std::string[3] CubeRotationSupportForStupidMe::getBottomPartOfSide() {
    return side[2];
}

int CubeRotationSupportForStupidMe::getTopPartOfSide() {
   return side[0];
}

int CubeRotationSupportForStupidMe::getLeftPartOfSide() {
    std::string line[3];
    line[0] = side[0][0];
    line[1] = side[1][0];
    line[2] = side[2][0];
    return line;
}

int CubeRotationSupportForStupidMe::getRightPartOfSide() {
    std::string line[3];
    line[0] = side[0][2];
    line[1] = side[1][2];
    line[2] = side[2][2];
    return line;
}
