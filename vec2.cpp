#include <stdio.h>
#include <stdlib.h>
struct vec2 {
    int x;
    int y;
    void add(vec2 v) {
        this -> x += v.x;
        this -> y += v.y;
    }
    void sub(vec2 v) {
        this -> x -= v.x;
        this -> y -= v.y;
    }
    void mult (vec2 v) {
        this -> x *= v.x;
        this -> y *= v.y;
    }
    void div (vec2 v) {
        this -> x /= v.x;
        this -> x /= v.y;
    }
};
int main(int argc, char** argv) {
    vec2 v1 = {24, 36};
    vec2 v2 = {4, 9};
    v1.add(v2);
    printf("x: %i, y: %i\n", v1.x, v1.y);
    v1.sub(v2);
    printf("x: %i, y: %i\n", v1.x, v1.y);
    v1.div(v2);
    printf("x: %i, y: %i\n", v1.x, v1.y);
    v1.mult(v2);
    printf("x: %i, y: %i\n", v1.x, v1.y);
    return 0;
}