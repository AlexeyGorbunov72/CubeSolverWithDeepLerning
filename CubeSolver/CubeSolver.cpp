//
// Created by Alexey on 24.05.2020.
//

#include "CubeSolver.h"
std::vector<string > CubeSolver::solveTheCube(Cube cube) {
    Model model;
    std::vector<std::string > answer;
    std::vector<Cube> sequenceVector;
    std::vector<Cube> bufferSequenceVector;
    std::vector<int* > flatsVector;
    std::vector<std::vector<double > > policy;

    //std::vector<std::vector<double >, Cube> policyAndCubes;
    sequenceVector.push_back(cube);
    for(int j = 0; j < 1000; j++){
        flatsVector.clear();
        policy.clear();
        for(Cube& cubeToFlat: sequenceVector){
            int* buffer = cubeToFlat.transformCubeForNN();
            std::vector<double > prediction = model.predict(buffer);
            std::vector<int > topTwoMoves = model.topTwoPredictions(prediction);
            bufferSequenceVector.push_back(cubeToFlat.doRotation(topTwoMoves[0]));

            if((*bufferSequenceVector.end()).isItSolve()){
                return (*bufferSequenceVector.end()).getHistory();
            }
            bufferSequenceVector.push_back(cubeToFlat.doRotation(topTwoMoves[1]));

            if((*bufferSequenceVector.end()).isItSolve()){
                return (*bufferSequenceVector.end()).getHistory();
            }

        }
        sequenceVector = bufferSequenceVector;
        bufferSequenceVector.clear();
    }
}