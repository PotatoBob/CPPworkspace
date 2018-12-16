#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char** argv) {
    int w, h, n;
    unsigned char *imageData = stbi_load("pineapple.jpg", &w, &h, &n, 0);
    FILE *file = fopen("newfile.txt", "w+");
    if(!file) {
        return 1;
    }
    fwrite(imageData, sizeof(char), w*h*4, file);

    stbi_image_free(imageData);
    fclose(file);
}