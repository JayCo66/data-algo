#include <stdio.h>

int CountingNum (int i){
    int count = 0;
    do{
        i/=10;
        count++;
    } while (i!=0);

    return count;
}

int main(){
    int n,num = 0;
    scanf("%d",&n);

    for(int i=1; i<=n; i++){
        num = num + CountingNum(i);
    }

    printf("%d",num);
}