#pragma once
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "RubikCube.h"
#include "Color.h"
#include "../Model/Model.h"
#define SIZE 1000

void initCube(int argc, char** argv, unsigned int* color_position, Model &model);
void initCube(int argc, char** argv, Model &model);