#include <stdio.h>
#include <string.h>

int minDeciBinarySum(char* n) {
    int max_digit = 0;
    for (int i = 0; i < strlen(n); ++i) {
        int digit = n[i] - '0';
        if (digit > max_digit) {
            max_digit = digit;
        }
    }
    return max_digit;
}

int main() {
    char n[100];  // Assuming the input string won't exceed 100 characters
    printf("Enter a positive decimal integer: ");
    scanf("%s", n);

    printf("Minimum number of positive deci-binary numbers needed: %d\n", minDeciBinarySum(n));

    return 0;
}
