#include <stdio.h>

int comparisonCount = 0; // Global variable to count comparisons

void merge(int low, int mid, int high, int n, int array[n]) {
    int i = low, j = mid + 1, k = low;
    int c[n];

    while (i <= mid && j <= high) {
         // Increment comparison count for each comparison
        if (array[i] < array[j]) {
            c[k] = array[i];
            i++;
        } else {
            c[k] = array[j];
            j++;
            comparisonCount+= (mid - i + 1);
        }
        k++;
    }

    while (i <= mid) {
        c[k] = array[i];
        i++;
        k++;
    }

    while (j <= high) {
        c[k] = array[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++) {
        array[i] = c[i];
    }
}

void  merge_sort(int low, int high, int n, int array[n]) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(low, mid, n, array);
        merge_sort(mid + 1, high, n, array);
        merge(low, mid, high, n, array);
    }
}

int main() {
    int i;
    int array[20], n;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    printf("Enter the elements of the array\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    merge_sort(0, n - 1, n, array);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\nNumber of comparisons: %d\n", comparisonCount);

    return 0;
}
