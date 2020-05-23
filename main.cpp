#include <iostream>
#include "Dense.h"
using namespace std;
int main() {
    Dense newDense("dense3.txt");
    for(int i = 0; i < 1024; i++){

        for(int j = 0; j < 1024; j++){
            cout<< newDense.weightsIn[i][j] << " ";
        }
        return 0;
        cout<< endl;
    }
    return 0;
}