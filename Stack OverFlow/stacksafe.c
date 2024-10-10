#include <stdio.h>


void process_user_input(int user_value, int max) {
    int stack_data[1000]; // Large stack allocation to speed up overflow
       if (user_value > 0 && max > 0) {
        process_user_input(user_value - 1, max -1);  
    }
}

int main() {
    // Simulate user input from the web service
    int user_value = 100000;  // Malicious input triggers deep recursion
    int max_depth = 3; // Limit the recursion depth by setting a maximum value
    process_user_input(user_value , max_depth);
    return 0;
}
