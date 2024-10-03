#include <stdio.h>
#include <stdbool.h>

bool isPrime (int x){
    if (x < 2) 
    return false;
    if (x == 2) 
    return true;
    if (x % 2 == 0) 
    return false;

    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

bool isPalindrome (int x){
    int palindrome = 0;
    int num = x;

    while (x > 0) {
        palindrome = palindrome * 10 + x % 10;
        x /= 10;
    }

    return palindrome == num;
}

int PrimePalindrome (int x){
    int Lx = x - 1, Rx = x + 1;

    while (1) {
        if (Lx > 1 && isPrime(Lx) && isPalindrome(Lx)) {
            return Lx;
        }
        if (isPrime(Rx) && isPalindrome(Rx)) {
            return Rx;
        }
        Lx--;
        Rx++;
    }
}

int main (){
    int x;
    scanf("%d", &x);

    if (x == 1) {
        printf("2\n");
        return 0;
    }

    if (isPrime(x) && isPalindrome(x)) {
        printf("%d\n", x);
    } else {
        printf("%d\n", PrimePalindrome(x));
    }

    return 0;
}
