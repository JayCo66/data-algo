#include <stdio.h>
#include <string.h>

void convertToRoman(int num, int *counts) {
    char *roman[] = {"C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    char result[20] = "";
    
    for (int i = 0; i < 9; i++) {
        while (num >= values[i]) {
            strcat(result, roman[i]);
            num -= values[i];
        }
    }
    
    for (int i = 0; i < strlen(result); i++) {
        switch (result[i]) {
            case 'I':
                counts[0]++;
                break;
            case 'V':
                counts[1]++;
                break;
            case 'X':
                counts[2]++;
                break;
            case 'L':
                counts[3]++;
                break;
            case 'C':
                counts[4]++;
                break;
        }
    }
}

int main() {
    int n;
    int counts[5] = {0};
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        convertToRoman(i, counts);
    }
    
    printf("%d %d %d %d %d\n", counts[0], counts[1], counts[2], counts[3], counts[4]);
    
    return 0;
}
