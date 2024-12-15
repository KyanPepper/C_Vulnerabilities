
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define StructA with a "safe" function pointer
typedef struct {
    char name[20];
    void (*safeFunction)();
} StructA;

// Define StructB with an "unsafe" function pointer (potentially dangerous)
typedef struct {
    double dummyValue;
    void (*unsafeFunction)();
} StructB;

// A safe function to print a message
void safeFunction() {
    printf("Safe function called!\n");
}

// An unsafe function that launches a shell (simulating malicious behavior)
void unsafeFunction() {
    printf("Launching shell...\n");
    system("/bin/sh");
}

int main() {
    // Allocate and initialize StructA
    StructA *a = (StructA *)malloc(sizeof(StructA));
    if (!a) {
        printf("Memory allocation failed\n");
        return 1;
    }
    strncpy(a->name, "StructA_Instance", sizeof(a->name));
    a->safeFunction = safeFunction;
    printf("StructA: Name = %s\n", a->name);

    // Call the safe function through StructA
    a->safeFunction();

    // Free StructA without setting the pointer to NULL
    free(a);

    // Allocate StructB, potentially overlapping the memory of StructA
    StructB *b = (StructB *)malloc(sizeof(StructB));
    if (!b) {
        printf("Memory allocation failed\n");
        return 1;
    }
    b->dummyValue = 3.14159;
    b->unsafeFunction = unsafeFunction; // Assign the unsafe function
    printf("StructB: DummyValue = %.2f\n", b->dummyValue);

    // Attempt to call StructA's safeFunction using the stale pointer `a`
    // Since memory overlaps, it may now call StructB's unsafeFunction
    printf("Calling stale safeFunction pointer (undefined behavior)...\n");
    a->safeFunction();

    // Free StructB
    free(b);

    return 0;
}
