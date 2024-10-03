#include <stdio.h>
#include <stdbool.h>

bool isPrime (int x){

    bool prime = true;
    int i;

    if (x%2==0 && x!=2){
        prime = false;
    }else
    for(i=3; i*i<=x; i+=2){
        if(x%i==0){
            prime = false;
            break;
        }
    }
    return prime;
}

void PrimeC (int x){

    int Lx = x-1, Rx = x+1;

    while(1){
        if(isPrime(Lx)&&isPrime(Rx)){
            printf("%d",Lx);
            break;
        }
        else if(isPrime(Lx)){
            printf("%d",Lx);
            break;
        }
        else if(isPrime(Rx)){
            printf("%d",Rx);
            break;
        }
        else{
            Lx--,Rx++;
        }
    }
}

int main (){

    int x;
    scanf("%d",&x);

    if(x==1){
        printf("2");
        return 0;
    }

    if(isPrime(x)){
        printf("%d",x);
    }else{
        PrimeC(x);
    }

return 0;
}