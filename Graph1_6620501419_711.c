#include <stdio.h>
#include <string.h>
int n; //number of vertices

int Top = -1;//stack functions & variables
int S[10];
void push(int index){
    Top++;
    S[Top] = index;
}

int pop(){
    Top--;
    return S[Top+1];
}

int Front = -1 , Rear = -1; //queue functions & variables
int size = 0;
int Q[10];

int isFull(){
    return (size>10) ? 1:0;
}

int isEmpty(){
    return size == 0 ? 1:0;
}

void enqueue(int index){
    if(!isFull()){
        if(Front == -1 && Rear == -1){
            Front = Rear = 0;
        }else{
            Rear = (Rear+1)%10;
        }
        Q[Rear] = index;
        size = size+1;
    }
}

int dequeue(){
    int index = Q[Front];
    Front = (Front+1)%10;
    size = size - 1;
    return index;
}

void DFT(char V[],int G[n][n],int status[]){
    for(int i=0;i<n;i++){
        status[i] = 1;
    }
    push(0);
    status[0] = 2;
    while(Top > -1){
        int current = pop();
        printf("%c ",V[current]);
        status[current] = 3;

        for(int i=0;i<n;i++){
            if(G[current][i] == 1 && status[i] == 1){
                push(i);
                status[i] = 2;
            }
        }
    }
}

void BFT(char V[],int G[n][n],int status[]){
    for(int i=0; i<n; i++){
        status[i] = 1;
    }
    enqueue(0);
    status[0] = 2;

    while(!isEmpty()){
        int current = dequeue();
        printf("%c ",V[current]);
        status[current] = 3;

        for(int i=0;i<n;i++){
            if(G[current][i] == 1 && status[i] == 1){
                enqueue(i);
                status[i] = 2;
            }
        }
    }
}

int main()
{
    int i,j;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    int status[n]; // Array for tracking status of each node
    int G[n][n]; // Array for representing Graph
    char V[n+1]; // Array for representing set of vertices
    printf("Enter node's name:");
    scanf("%s",V);
    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&G[i][j]);
        }
    }
    printf("DFS Traversal: ");
    DFT(V,G,status);

    printf("\nBFS Traversal: ");
    BFT(V,G,status);
}
