//
// Created by Alexey on 23.05.2020.
//

#include "Cube.h"
Cube::Cube() {
    // init action map
    actionMap["F"]  = 0;
    actionMap["B"]  = 1;
    actionMap["U"]  = 2;
    actionMap["D"]  = 3;
    actionMap["L"]  = 4;
    actionMap["R"]  = 5;
    actionMap["F'"] = 6;
    actionMap["B'"] = 7;
    actionMap["U'"] = 8;
    actionMap["D'"] = 9;
    actionMap["L'"] = 10;
    actionMap["R'"] = 11;
    // end init action map

    // init colorMap
    colorMap["green"]   = "100000";
    colorMap["blue"]    = "010000";
    colorMap["yellow"]  = "001000";
    colorMap["red"]     = "000100";
    colorMap["orange"]  = "000010";
    colorMap["white"]   = "000001";
    // end init colorMap

    // init cube sides
    for(int i = 0; i < 6; i++){
        std::string currientColor = "";
        switch(i){
            case 0: // F
                currientColor = "green";
                break;
            case 1: // B
                currientColor = "blue";
                break;
            case 2: // U
                currientColor = "yellow";
                break;
            case 3: // D
                currientColor = "white";
                break;
            case 4: // L
                currientColor = "red";
                break;
            case 5: // R
                currientColor = "orange";
                break;
        }

        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                theCubeData[i][j][k] = currientColor;
            }
        }
    }
    // end init the sides

}

int* Cube::transformCubeForNN() {
    int* flatCube = new int[324];
    int counter = 0;
    for(int i = 0; i < 6; i++){

        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                for(int stringPos = 0; stringPos < 6; stringPos++){
                    flatCube[counter] = colorMap[theCubeData[i][j][k]][stringPos] - '0';
                    counter++;
                }
            }
        }
    }
    for(int i = 0; i < 324; i++){
        std::cout << flatCube[i] << ", ";
    }
    return flatCube;

}
//          0 1 2
// 0 F    0 X X X
// 1 B    1 X X X
// 2 U    2 X X X
// 3 D
// 4 L
// 5 R
void Cube::F() {
    std::string newCube [6][3][3] = theCubeData;
    newCube[5][0][0] = theCubeData[2][2][0]; // R SIDE
    newCube[5][0][1] = theCubeData[2][2][1];
    newCube[5][0][2] = theCubeData[2][2][2];

    newCube[3][0][0] = theCubeData[5][0][2]; // D SIDE
    newCube[3][0][1] =
    newCube[3][0][2] = the c
}