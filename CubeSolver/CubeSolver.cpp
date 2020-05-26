//
// Created by Alexey on 24.05.2020.
//

#include "CubeSolver.h"
Cube CubeSolver::solveTheCube(Cube cube) {
    Model model;
    std::vector<std::string > answer;
    std::vector<Cube> sequenceVector;
    std::vector<Cube> bufferSequenceVector;
    std::vector<int* > flatsVector;
    std::vector<std::vector<double > > policy;

    //std::vector<std::vector<double >, Cube> policyAndCubes;
    sequenceVector.push_back(cube);
    for(int j = 0; j < 100; j++){
        flatsVector.clear();
        policy.clear();
        int sizeOfVector = sequenceVector.size();
        std::cout << "blyat " << sizeOfVector << std::endl;
        for(int i = 0; i < sizeOfVector; i++){
            Cube cubeToFlat = sequenceVector[i];
            int* buffer = cubeToFlat.transformCubeForNN();
            std::vector<double > prediction = model.predict(buffer);
            std::vector<int > topTwoMoves = model.topTwoPredictions(prediction);
            bufferSequenceVector.push_back(cubeToFlat.doRotation(topTwoMoves[0]));
            (*(bufferSequenceVector.end() - 1)).printCube((*(bufferSequenceVector.end() - 1)).theCubeData);
            std::cout <<"move 1: " << topTwoMoves[0] << "move 2: " << topTwoMoves[1]  << std::endl;
            if((*(bufferSequenceVector.end() - 1)).isItSolve()){
                std::cout << "sobral 0";

                return (*(bufferSequenceVector.end() - 1));
            }

            bufferSequenceVector.push_back(cubeToFlat.doRotation(topTwoMoves[1]));
            (*(bufferSequenceVector.end() - 1)).printCube((*(bufferSequenceVector.end() - 1)).theCubeData);
            if((*(bufferSequenceVector.end() - 1)).isItSolve()){
                std::cout << "sobral 1";

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