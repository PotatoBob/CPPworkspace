#include <stdio.h>

//1. Complete the functions below so that they print the individual bits of the passed in argument.
//   Use the main function to test them.
void printBinaryGeneral(int input, int numBits) {
    int decimal = input;
    int output[numBits];
    for(int i = 1; i <= numBits; i = i + 1) {
        output[numBits-i] = decimal & 1;
        decimal = decimal>>1;
    }
    for(int i = 0; i < numBits; i = i + 1) {
        printf("%i",output[i]);
    }
    printf("\n");
}

void print8BitBinary(unsigned char v){
    printBinaryGeneral(v, 8);
}

void print16BitBinary(unsigned short v){
    printBinaryGeneral(v, 16);
}

void print32BitBinary(unsigned int v){
    printBinaryGeneral(v, 32);
}

void print64BitBinary(unsigned long v){
    printBinaryGeneral(v, 64);
}

int main(int argc, char** argv){
    print8BitBinary(7);
    print16BitBinary(7);
    print32BitBinary(7);
    print64BitBinary(7);
    return 0;
}