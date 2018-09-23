#include "mat4.h"
#include "unit_test.h"

int main(int argc, char** argv) {
    //TEST 1: adding
    float m[4][4] = {{0, 1, 2, 3},
            {4, 5, 5, 7},
            {8, 9, 10, 11},
            {12, 13, 14, 15}};
    mat4 m1(m);
}