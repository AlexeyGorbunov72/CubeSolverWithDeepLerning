cmake_minimum_required(VERSION 3.15)
project(CubeSolverWithDeepLerning)

set(CMAKE_CXX_STANDARD 14)

add_executable(CubeSolverWithDeepLerning main.cpp Layers/Dense.cpp Layers/LayerLeakyReLU.cpp Model/Model.cpp Layers/InputLayer.cpp Layers/LayerSoftmax.cpp ActivationFunctions/SetOfActivationFun.cpp Cube/Cube.cpp CubeSolver/CubeSolver.cpp)
