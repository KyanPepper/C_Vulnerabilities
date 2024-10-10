#include <stdio.h>

// Vulnerable recursive function in a web service
void process_user_input(int user_value) {
    int stack_data[1000]; // Large stack allocation to speed up overflow

    // Vulnerable to deep recursion triggered by malicious input
    if (user_value > 0) {
        process_user_input(user_value - 1);  // No recursion depth limit
    }
}

int main() {
    // Simulate user input from the web service
    int user_value = 100000;  // Malicious input triggers deep recursion
    process_user_input(user_value);
    return 0;
}
