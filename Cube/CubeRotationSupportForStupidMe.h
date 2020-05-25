//
// Created by Alexey on 25.05.2020.
//
#pragma once
class CubeRotationSupportForStupidMe {
    std::string side[3][3];
    CubeRotationSupportForStupidMe();

    std::string[3] getLeftPartOfSide();
    std::string[3] getRightPartOfSide();
    std::string[3] getTopPartOfSide();
    std::string[3] getBottomPartOfSide();
};


