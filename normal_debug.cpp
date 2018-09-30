#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    /*for(int i = 0; i < argc; i = i + 1) {
        printf("%s\n", argv[i]);
    }*/
    if(strcmp(argv[1],"debug")==0) {
        printf("running in debug mode\n");
    } else {
        printf("running in normal mode\n");
    }
    return 0;
}
