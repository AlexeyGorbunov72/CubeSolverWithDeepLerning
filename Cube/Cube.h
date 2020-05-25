//
// Created by Alexey on 23.05.2020.
//

#pragma once

#include "iostream"
#include "string"
#include <map>
class Cube {
    std::map<std::string, int> actionMap;
    std::map<std::string, std::string> colorMap;
    int action;

public:
    std::string theCubeData[6][3][3];
    Cube();
    void R();
    void Rn();
    void F();
    void Fn();
    void U();
    void Un();
    void B();
    void Bn();
    void D();
    void Dn();
    void L();
    void Ln();
    int* transformCubeForNN();

};

