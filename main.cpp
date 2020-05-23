#include <iostream>
#include "Dense.h"
#include <iomanip>
using namespace std;
int main() {
    cout << std::setprecision(16);
    Dense newDense("./dense3.txt");
    for(int i = 0; i < 1024; i++){

        for(int j = 0; j < 1024; j++){
            cout<< newDense.weightsIn[i][j] << " ";
        }

        cout<< endl;
    }
    for(int i = 0; i < 1024; i++) {
        cout << newDense.weightsOut[i] << endl;
    }

    return 0;
}