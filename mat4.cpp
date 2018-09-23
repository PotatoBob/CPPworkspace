#include "mat4.h"

// This constructor initializes the 2d float array with v along
// the diagnal [(0, 0), (1, 1), (2, 2), (3, 3)]. The rest of
// the matrix will be zeros.
mat4::mat4(float v){
    for(int i = 0; i < 4; i++) {
        this->m[i][i] = v;
    }
}

//This constructor initializes the 2d float array
//with the float array m
mat4::mat4(float m[4][4]) {
    for(int i = 0; i < 4; i ++) {
        for(int j = 0; j < 4; j++) {
            this->m[i][j] = m[i][j];
        }
    }
}

// Copy Constructor. Initilaizes this matrix with the values of the
// passed in matrix.
mat4::mat4(mat4& m){
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            this->m[i][j] = m.m[i][j];
        }
    }
}

// Adds the values of m to this matrix.
void mat4::add(mat4 m){
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            this->m[i][j] += m.m[i][j];
        }
    }
}

// Subtracts the values of m from this matrix
void mat4::subtract(mat4 m){
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            this->m[i][j] -= m.m[i][j];
        }
    }
}

// Multiplies this matrix and m together.
// If you are unfamiliar with the algorithm of multiplying matrices,
// go to this site for an introduction:
// https://www.mathsisfun.com/algebra/matrix-multiplying.html
void mat4::multiply(mat4 m){
    mat4 matTemp;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int tempSum = 0;
            for(int k = 0; k < 4; k++) {
                tempSum += (this->m[i][k]*m.m[k][j]);
            }
            matTemp.m[i][j] = tempSum;
        }
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            this->m[i][j] = matTemp.m[i][j];
        }
    }
}

// Multiplies m1 and m2 and returns the result.
mat4 mat4::multiply(mat4 m1, mat4 m2){
    mat4 m = m1;
    m.multiply(m2);
    return m;
}

// Adds m1 and m2 and returns the result.
mat4 mat4::add(mat4 m1, mat4 m2){
    mat4 m = m1;
    m.add(m2);
    return m;
}

// subtracts m2 from m1 and returns the result.
mat4 mat4::subtract(mat4 m1, mat4 m2){
    mat4 m = m1;
    m.subtract(m2);
    return m;
}