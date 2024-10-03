#include <stdio.h>
#include <math.h>

int n = 0;

void swap(int H[],int a,int b){
    int temp = H[a];
    H[a] = H[b];
    H[b] = temp;
}

void insertHeap(int newval,int H[]){
    int i = n;
    n++;
    H[i] = newval;
    while(i >= 0){
        int par = (i-1)/2;
        if(H[i] < H[par]){
            swap(H,i,par);
            i = par;
        }else{
            break;
        }
    }
}

int main(){
    int maxheap;
    scanf("%d",&maxheap);
    int H[maxheap],newval;
    while(n < maxheap){
         scanf("%d",&newval);
         insertHeap(newval,H);
    }
    int level = 1;
    for(int i=0;i<maxheap;i++){
        if(i == pow(2,level)-1){
            printf("\n");
            level++;
        }
        printf("%d ",H[i]);
    }
}
