#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void vulnFunction(char *input) {
    char buffer[5]; //This is our buffer
    strncpy(buffer, input, sizeof(buffer) - 1); // This is a buffer -- This is the vulnerability we are exploiting
    buffer[sizeof(buffer) - 1] = '\0'; // Ensure null-termination
    printf("Buffer: %s\n", buffer);
}

void debug() {
    printf("Debugging mode activated\n");
    system("/bin/sh"); // This is a backdoor
}

int main() {
    char input[100]; //This our input buffer
    printf("Enter your name: "); 
    fgets(input, sizeof(input), stdin); // This is a safer alternative to gets
    input[strcspn(input, "\n")] = '\0'; // Remove newline character if present
    vulnFunction(input);
    return 0;
}
