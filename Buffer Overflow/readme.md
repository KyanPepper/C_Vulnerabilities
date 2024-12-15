# C Vulnerabilities
##x
## 1. Buffer Overflow
Buffer overflow is a vulnerability in which data is written to a buffer outside of the allocated space. This can lead to overwriting of adjacent memory locations, which can be exploited by an attacker to execute arbitrary code or crash the program.

### Mitigation
To prevent buffer overflow vulnerabilities, developers should follow these best practices:
1. Use safe string functions: Use functions like `strncpy` and `strncat` instead of `strcpy` and `strcat` to ensure that the destination buffer is not overflowed.
2. Validate input: Validate input data to ensure that it does not exceed the buffer size.
3. Use stack canaries: Use stack canaries to detect buffer overflows by placing a random value between the buffer and the return address on the stack.
4. Use address space layout randomization (ASLR): ASLR randomizes the memory layout of a process to make it harder for attackers to predict the location of buffers.
