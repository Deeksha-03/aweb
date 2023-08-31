#include <stdio.h>
#include <stdbool.h>

int max(int a, int b) {
    return a > b ? a : b;
}

bool isBalanced(int tree[], int size) {
    for (int i = 0; i < size; ++i) {
        if (tree[i] == -1) {
            continue; // Skip null nodes
        }

        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;

        if((tree[leftChildIndex]==-1 && tree[rightChildIndex]!=-1)||(tree[leftChildIndex]!=-1 && tree[rightChildIndex]==-1))
            return false;
    }

    return true;
}

int main() {
    int tree[] = { 3, 9, 20, -1, -1, 15, 7 };
    int size = sizeof(tree) / sizeof(tree[0]);

    if (isBalanced(tree, size)) {
        printf("The tree is height-balanced.\n");
    } else {
        printf("The tree is not height-balanced.\n");
    }

    return 0;
}
