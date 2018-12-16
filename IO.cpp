#include <stdio.h>
int main(int argc, char** argv) {
    FILE *file = fopen("IO.cpp", "r");
    if(!file) {
        return 1;
    }
    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    rewind(file);
    char *fileText = new char[fileSize];
    fread(fileText, sizeof(char), fileSize, file);
    printf("%s\n", fileText);

    /*char c = fgetc(file);
    printf("%c\n", c);
    char line[256];
    fgets(line, 256, file);
    printf("%s\n", line);*/

    fclose(file);
    file = fopen("newfile.txt", "w+");
    fwrite("abcd", sizeof(char), 4, file);
    fclose(file);
}