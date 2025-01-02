#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

int main()
{
    int N,K,input;
    int size = 0;
    scanf("%d %d",&N,&K);
    int Q[N];
    int Front = -1;
    int Rear = -1;

    for(int i=0;i<N;i++){
        scanf("%d",&input);
        if(Front == -1 || Rear == -1){
            Front = Rear = 0;
        }else{
            Rear = (Rear + 1)%N;
        }
        Q[Rear] = input;
        size++;
    }

    for(int i=K-1;i>=Front;i--){
        printf("%d ",Q[i]);
    }

    for(int i=K;i<=Rear;i++){
        printf("%d ",Q[i]);
    }
}