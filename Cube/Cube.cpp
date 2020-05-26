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
void Cube::printCube(std::string cube[6][3][3]){
    for(int i = 0; i < 6; i++){
        std::cout <<std::endl;
        for(int j = 0; j < 3; j++){
            std::cout << std::endl;
            for(int k = 0; k < 3; k++){
                std::cout << cube[i][j][k][0];
            }
        }
    }
}
//               0 1 2
// 0 F  g        0 X X X
// 1 B  b        1 X X X
// 2 U  y        2 X X X
// 3 D  w
// 4 L  r
// 5 R  o
void Cube::F() {
    std::string newCube[6][3][3];
    CubeRotationSupportForStupidMe greenSide(theCubeData, 0);
    CubeRotationSupportForStupidMe orangeSide(theCubeData, 5);
    CubeRotationSupportForStupidMe redSide(theCubeData, 4);
    CubeRotationSupportForStupidMe whiteSide(theCubeData, 3);
    CubeRotationSupportForStupidMe yellowSide(theCubeData, 2);

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                newCube[i][j][k] = theCubeData[i][j][k];
            }
        }
    }

    for(int i = 0; i < 3; i++){       // change the yellow side
        newCube[2][2][i] = redSide.getRightPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){       // change the orange side
        newCube[5][i][0] = yellowSide.getBottomPartOfSide()[i];
    }

    for(int i = 0; i < 3; i++){       // change the white side
        newCube[3][0][i] = orangeSide.getLeftPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){       // change the red side
        newCube[4][i][2] = whiteSide.getTopPartOfSide()[i];
    }

    for(int i = 0; i < 3; i++){
        newCube[0][0][i] = greenSide.getLeftPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){
        newCube[0][i][2] = greenSide.getTopPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[0][2][i] = greenSide.getRightPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){
        newCube[0][i][0] = greenSide.getBottomPartOfSide()[i];
    }
    printCube(newCube);
}

void Cube::L() {
    std::string newCube[6][3][3];
    CubeRotationSupportForStupidMe greenSide(theCubeData, 0);
    CubeRotationSupportForStupidMe blueSide(theCubeData, 1);
    CubeRotationSupportForStupidMe redSide(theCubeData, 4);
    CubeRotationSupportForStupidMe whiteSide(theCubeData, 3);
    CubeRotationSupportForStupidMe yellowSide(theCubeData, 2);

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                newCube[i][j][k] = theCubeData[i][j][k];
            }
        }
    }

    for(int i = 0; i < 3; i++){
        newCube[0][i][0] = yellowSide.getLeftPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[3][i][0] = greenSide.getLeftPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[2][i][0] = blueSide.getRightPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){
        newCube[1][i][2] = whiteSide.getLeftPartOfSide()[2 - i];
    }

    for(int i = 0; i < 3; i++){
        newCube[4][0][i] = redSide.getLeftPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){
        newCube[4][i][2] = redSide.getTopPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[4][2][i] = redSide.getRightPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){
        newCube[4][i][0] = redSide.getBottomPartOfSide()[i];
    }
    printCube(newCube);
}

void Cube::R() {
    std::string newCube[6][3][3];
    CubeRotationSupportForStupidMe greenSide(theCubeData, 0);
    CubeRotationSupportForStupidMe blueSide(theCubeData, 1);
    CubeRotationSupportForStupidMe orangeSide(theCubeData, 5);
    CubeRotationSupportForStupidMe whiteSide(theCubeData, 3);
    CubeRotationSupportForStupidMe yellowSide(theCubeData, 2);

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                newCube[i][j][k] = theCubeData[i][j][k];
            }
        }
    }

    for(int i = 0; i < 3; i++){
        newCube[2][i][2] = greenSide.getLeftPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[0][i][2] = whiteSide.getLeftPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[1][i][0] = yellowSide.getRightPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){
        newCube[3][i][2] = blueSide.getLeftPartOfSide()[2 - i];
    }

    for(int i = 0; i < 3; i++){
        newCube[5][0][i] = orangeSide.getLeftPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){
        newCube[5][i][2] = orangeSide.getTopPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[5][2][i] = orangeSide.getRightPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){
        newCube[5][i][0] = orangeSide.getBottomPartOfSide()[i];
    }
    printCube(newCube);
}

void Cube::B() {
    std::string newCube[6][3][3];
    CubeRotationSupportForStupidMe redSide(theCubeData, 4);
    CubeRotationSupportForStupidMe blueSide(theCubeData, 1);
    CubeRotationSupportForStupidMe orangeSide(theCubeData, 5);
    CubeRotationSupportForStupidMe whiteSide(theCubeData, 3);
    CubeRotationSupportForStupidMe yellowSide(theCubeData, 2);

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                newCube[i][j][k] = theCubeData[i][j][k];
            }
        }
    }

    for(int i = 0; i < 3; i++){
        newCube[2][0][i] = orangeSide.getRightPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[3][2][i] = redSide.getLeftPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[5][i][2] = whiteSide.getRightPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){
        newCube[4][i][0] = yellowSide.getLeftPartOfSide()[2 - i];
    }

    for(int i = 0; i < 3; i++){
        newCube[1][0][i] = blueSide.getLeftPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){
        newCube[1][i][2] = blueSide.getTopPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[1][2][i] = blueSide.getRightPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){
        newCube[1][i][0] = blueSide.getBottomPartOfSide()[i];
    }
    printCube(newCube);
}

void Cube::D() {
    std::string newCube[6][3][3];
    CubeRotationSupportForStupidMe redSide(theCubeData, 4);
    CubeRotationSupportForStupidMe blueSide(theCubeData, 1);
    CubeRotationSupportForStupidMe orangeSide(theCubeData, 5);
    CubeRotationSupportForStupidMe whiteSide(theCubeData, 3);
    CubeRotationSupportForStupidMe greenSide(theCubeData, 0);

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                newCube[i][j][k] = theCubeData[i][j][k];
            }
        }
    }

    for(int i = 0; i < 3; i++){
        newCube[0][2][i] = redSide.getBottomPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[5][2][i] = greenSide.getBottomPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[1][2][i] = orangeSide.getBottomPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[4][2][i] = blueSide.getBottomPartOfSide()[i];
    }

    for(int i = 0; i < 3; i++){
        newCube[3][0][i] = whiteSide.getLeftPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){
        newCube[3][i][2] = whiteSide.getTopPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[3][2][i] = whiteSide.getRightPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){
        newCube[3][i][0] = whiteSide.getBottomPartOfSide()[i];
    }
    printCube(newCube);
}

void Cube::U() {
    std::string newCube[6][3][3];
    CubeRotationSupportForStupidMe redSide(theCubeData, 4);
    CubeRotationSupportForStupidMe blueSide(theCubeData, 1);
    CubeRotationSupportForStupidMe orangeSide(theCubeData, 5);
    CubeRotationSupportForStupidMe yellowSide(theCubeData, 2);
    CubeRotationSupportForStupidMe greenSide(theCubeData, 0);

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                newCube[i][j][k] = theCubeData[i][j][k];
            }
        }
    }

    for(int i = 0; i < 3; i++){
        newCube[1][0][i] = redSide.getTopPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[4][0][i] = greenSide.getTopPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[0][0][i] = orangeSide.getTopPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[5][0][i] = blueSide.getTopPartOfSide()[i];
    }

    for(int i = 0; i < 3; i++){
        newCube[2][0][i] = yellowSide.getLeftPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){
        newCube[2][i][2] = yellowSide.getTopPartOfSide()[i];
    }
    for(int i = 0; i < 3; i++){
        newCube[2][2][i] = yellowSide.getRightPartOfSide()[2 - i];
    }
    for(int i = 0; i < 3; i++){
        newCube[2][i][0] = yellowSide.getBottomPartOfSide()[i];
    }
    printCube(newCube);
}