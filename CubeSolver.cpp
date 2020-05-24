//
// Created by Alexey on 24.05.2020.
//

#include "CubeSolver.h"
void CubeSolver::solveTheCube(Cube cube) {
    Model model;
    std::vector<std::string > answer;
    std::vector<Cube> sequenceVector;
    std::vector<int* > flatsVector;
    std::vector<std::vector<double > > policy;
    std::vector<std::vector<double >, Cube> policyAndCubes;
    sequenceVector.push_back(cube);
    for(int j = 0; j < 1000; j++){
        flatsVector.clear();
        policy.clear();
        for(Cube& cubeToFlat: sequenceVector){
            int* buffer = cubeToFlat.transformCubeForNN();
            std::vector<double > prediction = model.predict(buffer);
            policy.push_back(prediction);
        }
        std::vector<Cube > newSequnceVector;

        return;
    }
}