//
// Created by Alexey on 23.05.2020.
//
#pragma once

class Model {
        const string pathToWeights = "";
        Model();
        void loadWeighs();
    public:
        int predict(Cube cube);
};
