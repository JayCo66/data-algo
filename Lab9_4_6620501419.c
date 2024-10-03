#include <stdio.h>


int main(){
    int arrSize;
    scanf("%d",&arrSize);

    int T[arrSize];
    for(int i=0; i<arrSize; i++){
        scanf("%d",&T[i]);
    }

    int isBinaryTree = 1;
    int index = 0;
    
    while(index < (arrSize-1)/2){
        int leftChild = index*2+1;
        int rightChild = index*2+2;

        if(((T[index] < T[leftChild]) && T[leftChild] != 0) || ((T[index] > T[rightChild]) && T[rightChild] != 0)){
            isBinaryTree = 0;
            break;
        }else{
            index++;
        }
    }

    int value = 0;
    if(isBinaryTree){
        int high,low;
        scanf("%d %d",&low,&high);

        for(int i=0;i<arrSize;i++){
            if(T[i] >= low && T[i] <= high){
                value += T[i];
            }
        }
    }
    printf("%d\n",isBinaryTree);
    
    if(isBinaryTree){
        printf("%d",value);
    }
    

    return 0;
}