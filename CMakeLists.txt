cmake_minimum_required(VERSION 3.15)
project(CubeSolverWithDeepLerning)
#include_directories(GL)
#set(OpenGlLinkers -lglut -lGLU -lGL)


add_executable(CubeSolverWithDeepLerning
        main.cpp
        Graphix/Color.h
        Graphix/initGraphics.cpp
        Graphix/FragmentCube.cpp
        Graphix/RubikCube.cpp
        Layers/Dense.cpp
        Layers/LayerLeakyReLU.cpp
        Model/Model.cpp
        Layers/InputLayer.cpp
        Layers/LayerSoftmax.cpp
        ActivationFunctions/SetOfActivationFun.cpp
        Cube/Cube.cpp
        CubeSolver/CubeSolver.cpp
        Cube/CubeRotationSupportForStupidMe.cpp

        )



# Included these two lines:

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

#target_link_libraries(CubeSolverWithDeepLerning ${OpenGlLinkers}) # linking opengl libraries to the project

#target_link_libraries(OpenGL GL/Glaux.lib GL/GLU32.LIB GL/glui32.lib GL/glut32.lib GL/OPENGL32.LIB)
set(CMAKE_CXX_STANDARD 14)