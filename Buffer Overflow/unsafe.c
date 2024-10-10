#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void vulnFunction(char *input) {
    char buffer[5]; //This is our buffer
    strcpy(buffer, input);// This is a buffer -- This is the vulnerability we are exploiting
    printf("Buffer: %s\n", buffer);
}

void debug() {
    printf("Debugging mode activated\n");
    system("/bin/sh"); // This is a backdoor
}

int main() {
    char input[100]; //This our input buffer
    printf("Enter your name: "); 
    gets(&input); // This is a could be a buffer overflow, it does not check the size of the input
    vulnFunction(input);
    return 0;
}
