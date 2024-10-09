#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void vuln(char *input) {
    char buffer[100];
    strcpy(buffer, input);
}

void getPassword() {
    char password[100];
    printf("Enter the password: ");
    gets(password);
    printf("You entered");
    printf(password);
}

void debug() {
    printf("Debugging mode activated\n");
    system("/bin/sh");
}

int main() {
    
}
