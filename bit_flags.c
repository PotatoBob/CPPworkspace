#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREETING_FLAG  0x01 // prints a greeting
#define GOODBYE_FLAG   0x02 // prints "Goodbye"
#define RANDOM_FLAG    0x04 // prints a random number
#define FACT_FLAG      0x08 // prints a fun fact
#define QUOTE_FLAG     0x10 // prints a good quote
#define LOOP_FLAG      0x20 // prints the numbers 0 to 9 in a for loop
#define WARNING_FLAG   0x40 // prints a warning message
#define ERROR_FLAG     0x80 // prints an error message

void handleFlag(unsigned char flag){
    //1. Comeplete the handleFlag method so that it checks the bits of the flag parameter,
    //   and performs the repective action if that bit is set.
    if(flag & GREETING_FLAG) {
        printf("Hello there!\n");
    }
    if(flag & GOODBYE_FLAG) {
        printf("Goodbye\n");
    }
    if(flag & RANDOM_FLAG) {
        printf("%i\n", rand());
    }
    if(flag & FACT_FLAG) {
        printf("Fun fact: A kiwi egg is almost as big as the mother holding it!\n");
    }
    if(flag & QUOTE_FLAG) {
        printf("\"We are here on earth to help others. What the others are here for, I have no idea.\"\n~W.H. Auden\n");
    }
    if(flag & LOOP_FLAG) {
        for(int i = 0; i <= 9; i = i + 1) {
            printf("%i, ", i);
        }
        printf("\n");
    }
    if(flag & WARNING_FLAG) {
        printf("WARNING: THIS CODE IS POORLY WRITTEN!\n");
    }
    if(flag & ERROR_FLAG) {
        printf("ERROR: OUTPUT UNAVAILABLE.\n");
    }
}

int main(int argc, char** argv){
    srand(time(0));
    // TESTS    
    printf("CALL #1:\n");
    //should print only a greeting
    handleFlag(GREETING_FLAG);

    printf("CALL #2:\n");
    //should print goodbye and a fun fact
    handleFlag(GOODBYE_FLAG | FACT_FLAG);

    printf("CALL #3:\n");
    //should print a quite, numbers 0-9, and a warning
    handleFlag(QUOTE_FLAG | LOOP_FLAG | WARNING_FLAG);

    printf("CALL #4:\n");
    //should print a greeting and an error
    handleFlag(GREETING_FLAG | ERROR_FLAG);
    
    printf("CALL #5:\n");
    //should print them all
    handleFlag(GREETING_FLAG | GOODBYE_FLAG | RANDOM_FLAG| QUOTE_FLAG | LOOP_FLAG | WARNING_FLAG | ERROR_FLAG);

    return 0;
}