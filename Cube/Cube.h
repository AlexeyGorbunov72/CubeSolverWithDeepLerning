//
// Created by Alexey on 23.05.2020.
//

#pragma once

#include "iostream"
#include "string"
#include <map>
#include "CubeRotationSupportForStupidMe.h"
#include "vector"
class Cube {
    std::map<std::string, int> actionMap;
    std::map<std::string, std::string> colorMap;
    std::vector<std::string > historyOfMovements;

public:
    std::string theCubeData[6][3][3];
    bool isItSolve();
    Cube();
    Cube(std::string data[6][3][3]);
    Cube doRotation(int idOfRotation);
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

    void setHistory(std::vector<std::string> history){
        historyOfMovements = history;
    }
    void appendInHistory(std::string move){
        historyOfMovements.push_back(move);
    }
    std::vector<std::string> getHistory(){
        return historyOfMovements;
    }

};

