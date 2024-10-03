#include <stdio.h>
int numCompare=0,numSwap=0;

    void swap (int A[], int i, int j){
        int ptr;
        ptr = A[i];
        A[i] = A[j];
        A[j] = ptr;
    }

    void DisplayArray(int A[], int n)
    {
        int i;

        for (i=0; i< n; i++)
            printf("%d ", A[i]);
        printf("\n");
    }

    void InsertionSort(int A[], int n)
    {
        for(int i=1; i <= n-1; i++){
            int j=i;
            while(j>0){
                numCompare++;
                if(A[j]<A[j-1]){
                    swap(A,j,j-1);
                    numSwap++;
                }
                j=j-1;
            }
        }
    }

int main(int argc, const char * argv[]) {
    {
        int N;
        double Median;
        printf("Enter n: ");
        scanf("%d",&N);
        
        int A[N];
        
        for(int i=0;i<N;i++){
            scanf("%d",&A[i]);
        }
        InsertionSort(A,N);
        DisplayArray(A, N);
        
        if(N%2==1){
            Median = A[N/2];
        }else
            Median = (A[N/2]+A[N/2-1])/2.0;
        
        printf("Median=%.1lf\n",Median);
        
        return 0;
    }
}