#include <stdio.h>

int main() {
    int sum = 0;
    int i;

    // Inline assembly to calculate sum of first 10 integers
    __asm__(
        "movl $1, %%ebx;"       // Start with 1 (stored in EBX)
        "movl $10, %%ecx;"      // Loop counter set to 10 (stored in ECX)
        "xorl %%eax, %%eax;"    // Clear EAX (sum)

        "sum_loop:;"
        "addl %%ebx, %%eax;"    // Add EBX to EAX
        "incl %%ebx;"           // Increment EBX
        "loop sum_loop;"        // Decrement ECX and loop if not zero

        "movl %%eax, %0;"       // Store the result in 'sum'
        : "=r" (sum)           // Output operand
        :                       // No input operands
        : "eax", "ebx", "ecx"   // Clobbered registers
    );

    printf("Sum of first 10 integers: %d\n", sum);
    return 0;
}
