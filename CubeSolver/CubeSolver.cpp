//
// Created by Alexey on 24.05.2020.
//

#include "CubeSolver.h"
Cube CubeSolver::solveTheCube(Cube cube, Model& model) {

    std::vector<std::string > answer;
    std::vector<Cube> sequenceVector;
    std::vector<Cube> bufferSequenceVector;
    map<string, bool> existsCubes;

    sequenceVector.push_back(cube);
    for(int j = 0; j < 100; j++){

        int sizeOfVector = sequenceVector.size();
        for(int i = 0; i < sizeOfVector; i++){

            std::cout << "size of sequence: " << sizeOfVector << std::endl;
            Cube cubeToFlat = sequenceVector[i];
            if(existsCubes[cubeToFlat.transformToString()] != NULL){
                continue;
            }
            else{
                existsCubes[cubeToFlat.transformToString()] = true;
            }
            int* buffer = cubeToFlat.transformCubeForNN();
            std::vector<double > prediction = model.predict(buffer);
            std::vector<int > topTwoMoves = model.topTwoPredictions(prediction);

            bufferSequenceVector.push_back(cubeToFlat.doRotation(topTwoMoves[0]));
            (*(bufferSequenceVector.end() - 1)).printHistory();

            if((*(bufferSequenceVector.end() - 1)).isItSolve()){
                return (*(bufferSequenceVector.end() - 1));
            }

            bufferSequenceVector.push_back(cubeToFlat.doRotation(topTwoMoves[1]));
            (*(bufferSequenceVector.end() - 1)).printHistory();

            if((*(bufferSequenceVector.end() - 1)).isItSolve()){
                return (*(bufferSequenceVector.end() - 1));
            }

        }
        sequenceVector = bufferSequenceVector;
        bufferSequenceVector.clear();
    }
    for(Cube& cube: sequenceVector){
        std::cout << "- -  - - - - - -  - - -" << std::endl;
        cube.printCube(cube.theCubeData);
        std::cout << "- -  - - - - - -  - - -" << std::endl;
    }

}