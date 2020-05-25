//
// Created by Alexey on 25.05.2020.
//
#pragma once
#include "string"
class CubeRotationSupportForStupidMe {
    std::string side[3][3];
public:

    CubeRotationSupportForStupidMe(std::string cube[6][3][3], int index);
    std::string* getLeftPartOfSide();
    std::string* getRightPartOfSide();
    std::string* getTopPartOfSide();
    std::string* getBottomPartOfSide();
};


