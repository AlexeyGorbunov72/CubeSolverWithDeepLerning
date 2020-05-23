cmake_minimum_required(VERSION 3.15)
project(CubeSolverWithDeepLerning)

set(CMAKE_CXX_STANDARD 14)

add_executable(CubeSolverWithDeepLerning main.cpp Dense.cpp LayerLeakyReLU.cpp Model.cpp InputLayer.cpp LayerSoftmax.cpp SetOfActivationFun.cpp)
