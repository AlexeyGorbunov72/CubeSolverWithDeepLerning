//
// Created by Alexey on 23.05.2020.
//

#pragma once

#include "iostream"
#include "string"
#include <map>
#include "CubeRotationSupportForStupidMe.h"
class Cube {
    std::map<std::string, int> actionMap;
    std::map<std::string, std::string> colorMap;
    int action;

public:
    std::string theCubeData[6][3][3];
    Cube();
    Cube(std::string data[6][3][3]);
    void printCube(std::string cube[6][3][3]);
    Cube R();
    Cube Rn();
    Cube F();
    Cube Fn();
    Cube U();
    Cube Un();
    Cube B();
    Cube Bn();
    Cube D();
    Cube Dn();
    Cube L();
    Cube Ln();
    int* transformCubeForNN();

};

