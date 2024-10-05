#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int H[], int a, int b) {
    int temp = H[a];
    H[a] = H[b];
    H[b] = temp;
}

void BottomUp(int H[], int n) {
    int lastPar = n / 2 - 1;
    int left, right;
    for (int i = lastPar; i >= 0; i--) {
        int index = i;
        left = index * 2 + 1;
        right = index * 2 + 2;

        while (left < n) {
            int largest = index;
            if (left < n && H[left] > H[largest]) {
                largest = left;
            }
            if (right < n && H[right] > H[largest]) {
                largest = right;
            }
            if (largest != index) {
                swap(H, index, largest);
                index = largest;
            } else {
                break;
            }
            left = index * 2 + 1;
            right = index * 2 + 2;
        }
    }
}

void Ascending(int H[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        swap(H, 0, i);
        BottomUp(H, i);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", H[i]);
    }
    printf("\n");
}

void Descending(int H[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        swap(H, 0, i);
        BottomUp(H, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", H[i]);
    }
    printf("\n");
}

int main() {
    int i, n = 20;
    srand((unsigned) time(NULL));
    int num[n];
    
    printf("Numbers before sorting:\n");
    for (i = 0; i < n; i++) {
        num[i] = rand() % 100 + 1;
        printf("%d ", num[i]);
    }
    
    char select;
    printf("\nSorting (A)scending order\nSorting (D)escending order\nSelect choice: ");
    scanf(" %c", &select);

    printf("Numbers after sorting: ");
    
    if (select == 'A') {
        printf("Ascending order\n");
        BottomUp(num, n);
        Ascending(num, n);
    } else if (select == 'D') {
        printf("Descending order\n");
        BottomUp(num, n);
        Descending(num, n);
    }

    return 0;
}