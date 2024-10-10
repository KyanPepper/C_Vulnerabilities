#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void vulnFunction(char *input) {
    char buffer[5]; //This is our buffer
    strcpy(buffer, input);// This is a buffer overflow
}

void debug() {
    printf("Debugging mode activated\n");
    system("/bin/sh"); // This is a backdoor
}

int main() {
    char input[100]; //This our input buffer
    printf("Enter your name: "); 
    scanf(&input); // This is a could be a buffer overflow
    vulnFunction(input);
    return 0;
}
