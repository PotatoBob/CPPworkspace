#pragma once
#include <stdio.h>

struct String{
    static const unsigned char INITIAL_BUFFER_SIZE = 255;
private:
    // 1.
    // Three (3) private member variables are needed.
    // -a char pointer that will point to the first character in the string.
    // -an unsigned int to keep count of how many characters are in the string.
    // -an unsigned long to keep the size of the allotted space for the string in memory (known as the buffer). 
    char* loc;
    unsigned int charCount;
    unsigned long buffer;

    // 2.
    // the getLengthOfCharString function is a private helper function that 
    // returns the number of chars (bytes) before v points to the
    // null termination character '\0';
    unsigned int getLengthOfCharString(const char* v){
        unsigned int counter = 0;
        while(*v!='\0') {
            counter++;
            v++;
        }
        return counter;
    }

public:
    // 3.
    // the default constructor initializes the member variables
    // the buffer size should be initialized to the INITIAL_BUFFER_SIZE
    // the char pointer should point to a new char array that is the size of the buffer
    // the character count is 0
    String(){
        buffer = INITIAL_BUFFER_SIZE;
        loc = new char[buffer];
        charCount = 0;
    }

    // 4.
    // this constructor initializes this string object with the data 
    // referenced by the char pointer
    String(const char* v){
        

        // 4a: get the length of v
        if(getLengthOfCharString(v) < INITIAL_BUFFER_SIZE) {
        // 4b: if that length is less than the initial buffer size,
        //     initialize the char pointer member variable to point at 
        //     a new char array that is the size of the initial buffer size.
        //     Also, initialize the buffer size variable.
            buffer = INITIAL_BUFFER_SIZE;
            loc = new char[buffer];
        }
        // 4c: otherwise, initialize the char pointer to point at a new
        //     char array that is the size of v's length * 2.
        //     This is to give our string room to grow without having to 
        //     reallocate memory as often.
        else {
            loc = new char[getLengthOfCharString(v)*2];
        }
        // 4d: initialize the char count variable to equal the length of v.
        charCount = getLengthOfCharString(v);
        // 4e: copy that characters from v into the char array pointed to by the 
        // member variable (for loop)
        for(int i = 0; i < getLengthOfCharString(v); i++) {
            loc[i] = v[i];
        }
    }

    // 5.
    // This constructor copies the passed in string to this string. Since it is
    // being passed by reference, we have access to its private member variables.
    String(const String& s){
        // 5a: Initialize the char count and buffer size variables to match those of s.
        charCount = s.charCount;
        buffer = s.buffer;
        // 5b: initialize the char pointer member variable to point at 
        //     a new char array that is the size of the buffer size variable
        loc = new char[buffer];
        // 5c: copy the contents from s into the char array
        for(int i = 0; i < s.charCount; i++) {
                loc[i] = s.loc[i];
        }
    }

    // 6.
    // The destructor should check if the char pointer is null.
    // If not, delete the array it points to.
    ~String(){
        if(loc != 0) {
            delete[] loc;
        }
    }

    // 7. 
    // This function appends the contents of v to this string.
    void append(const char* v){
        // 7a:
        // First, check to make sure that adding the characters
        // to this string won't overflow the buffer.
        // If it will, then we need to reallocate new memory for the string.
        // Don't forget to clean up the old memory and to update the character count.
        if(charCount+getLengthOfCharString(v)>buffer) {
            char* locTemp = new char[charCount+getLengthOfCharString(v)*2];
            for(int i = 0; i < charCount; i++) {
                locTemp[i] = loc[i];
            }
            for(int i = 0; i < getLengthOfCharString(v); i++) {
                locTemp[i + charCount] = v[i];
            }
            delete[] loc;
            loc = locTemp;
            delete[] locTemp;
        } else {
            for (int i = 0; i < getLengthOfCharString(v); i++) {
                loc[i + charCount] = v[i];
            }
        }
        charCount = charCount + getLengthOfCharString(v);
    }

    // 8. 
    // This function appends the contents of str to this string.
    void append(const String& str){
        if(charCount + str.charCount > buffer) {
            char* locTemp = new char[charCount + str.charCount*2];
            for(int i = 0; i < charCount; i++) {
                locTemp[i] = loc[i];
            }
            for(int i = 0; i < str.charCount; i++) {
                locTemp[i + charCount] = str.loc[i];
            }
            delete[] loc;
            loc = locTemp;
            delete[] locTemp;
        } else {
            for(int i = 0; i < str.charCount; i++) {
                loc[i + charCount] = str.loc[i];
            }
        }
        charCount = charCount + str.charCount;
    }

    //9. getter function for the length of the string (total chars).
    unsigned int length(){
        return charCount;
    }

    //10. getter function that returns the location of the char array
    const char* getCharArray(){
        return loc;
    }

    //11. function that returns true if v contains all the same characters
    //    as this string
    bool equals(const char* v){
        int vLength = getLengthOfCharString(v);
        if(vLength != charCount) {
            return false;
        } else {
            for(int i = 0; i < charCount; i++) {
                //printf("loc: %c, v: %c\n", loc[i], v[i]);
                if(loc[i]!=v[i]) {
                    return false;
                }
            }
            return true;
        }
    }

    //12. function that returns true if s contains all the same characters
    //    as this string
    bool equals(const String& s){
        int sLength = s.charCount;
        char* sLoc = s.loc;
        if(sLength != charCount) {
            return false;
        } else {
            for(int i = 0; i < charCount; i++) {
                if(loc[i] != sLoc[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    
};