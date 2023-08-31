#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPowerOfFive(int num) {
    while (num > 1 && num % 5 == 0) {
        num /= 5;
    }
    return num == 1;
}

int minPartitions(char *s) {
    int n = strlen(s);
    int dp[n + 1]; // dp[i] represents the minimum beautiful substrings up to index i

    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = i; // Initialize with the maximum possible value
        for (int j = 1; j <= i; ++j) {
            if (s[j - 1] != '0' && isPowerOfFive(strtol(s + j - 1, NULL, 2))) {
                dp[i] = dp[i] < dp[j - 1] + 1 ? dp[i] : dp[j - 1] + 1;
            }
        }
    }

    return dp[n];
}

int main() {
    char s[100]; // Assuming the input won't exceed 100 characters
    printf("Enter a binary string: ");
    scanf("%s", s);

    int result = minPartitions(s);
    printf("Minimum number of beautiful substrings: %d\n", result);

    return 0;
}
