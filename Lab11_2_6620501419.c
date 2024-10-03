#include <stdio.h>
#include <math.h>

int n = 0;

void swap(int H[],int a,int b){
    int temp = H[a];
    H[a] = H[b];
    H[b] = temp;
}

int isMinHeap(int H[],int n){
    int isMinHeap = 1;
    for(int i=0;i<n;i++){
        if(2*i+2 <= n){
            int left = 2*i+1;
            int right = 2*i+2;
            if(H[left] < H[i] || H[right] < H[i]){
                isMinHeap = 0;
                break;
            }
        }


    }
    return isMinHeap;
}

int findMin(int H[], int a, int b){
    return (H[a] < H[b]) ? a:b;
}



void minHeapButtomUp(int H[], int n){
    int lastPar = n/2 - 1;
    int left, right, minChild;

    for(int i = lastPar; i >= 0; i--){
        int index = i;
        left = index * 2 + 1;
        right = index * 2 + 2;

        while(left < n){
            if (right < n && H[right] < H[left]){
                minChild = right;
            } else {
                minChild = left;
            }

            if(H[index] > H[minChild]){
                swap(H, index, minChild);

                index = minChild;
                left = index * 2 + 1;
                right = index * 2 + 2;
            } else {
                break;
            }
        }
    }
}

void DisplayMinHeap(int H[],int n){
    int level = 1;
    for(int i=0;i<n;i++){
        if(i == pow(2,level)-1){
            printf("\n");
            level++;
        }
        printf("%d ",H[i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int H[n];
    for(int i=0;i<n;i++){
        scanf("%d",&H[i]);
    }
    if(isMinHeap(H,n)){
        printf("a Min-Heap\n");
    }else{
        printf("Not a Min-Heap\n");
        minHeapButtomUp(H,n);
        DisplayMinHeap(H,n);
    }
}
