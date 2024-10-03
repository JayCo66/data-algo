#include <stdio.h>
#include <string.h>

struct node {
    int freq;
    char data;
};

int Top = -1;
struct node H[26];

void push(char data) {
    Top++;
    H[Top].data = data;
    H[Top].freq = 1;
}

struct node pop() {
    struct node temp = H[Top];
    Top--;
    return temp;
}

int find(char data) {
    for (int i = 0; i <= Top; i++) {
        if (H[i].data == data) {
            return i;
        }
    }
    return -1;
}

void peek(char data) {
    int index = find(data);
    if (index != -1) {
        H[index].freq += 1;
    } else {
        push(data);
    }
}

void swap(struct node H[], int a, int b) {
    struct node temp = H[a];
    H[a] = H[b];
    H[b] = temp;
}

void ButtomUp(struct node H[], int n) {
    int lastPar = n / 2 - 1;
    int left, right;
    for (int i = lastPar; i >= 0; i--) {
        int index = i;
        left = index * 2 + 1;
        right = index * 2 + 2;

        while (left < n) {
            int largest = index;
            if (left < n && H[left].freq > H[largest].freq) {
                largest = left;
            }
            if (right < n && H[right].freq > H[largest].freq) {
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

void heapSort(struct node H[], int n) {
    for (int i = n - 1; i > 0; i--) {
        swap(H, 0, i);
        ButtomUp(H, i);
    }
}

void displayH() {
    for (int i = Top; i >= 0; i--) {
        for (int j = 0; j < H[i].freq; j++) {
            printf("%c", H[i].data);
        }
    }
}

int main() {
    char input[50];
    fgets(input, sizeof(input), stdin);

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != '\n') {
            peek(input[i]);
        }
    }

    ButtomUp(H, Top + 1);
    heapSort(H, Top + 1);
    displayH();

    return 0;
}