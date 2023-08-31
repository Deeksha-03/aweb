#include <stdio.h>

#define MAX_COMBINATIONS 10000 // Maximum number of combinations
char current[MAX_COMBINATIONS];
int n;
void generateParentheses(int open, int close,int index)
{
    if (index == 2 * n)
    {
        current[index] = '\0';
        printf("%s\n", current);
        return;
    }

    if (open < n) {
        current[index] = '(';
        generateParentheses(open + 1, close,index + 1);
    }

    if (close < open) {
        current[index] = ')';
        generateParentheses(open, close + 1,index + 1);
    }
}

int main()
{
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Combinations of well-formed parentheses:\n");
    generateParentheses(0, 0,0);

    return 0;
}
