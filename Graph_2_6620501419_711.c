#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n; //number of vertices

struct node
{
    char data;
    struct node *next;
};

struct node* createNode(char data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}


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

void DFT(struct node *list[],int status[],char V[]){
    for(int i=0;i<n;i++){
        status[i] = 1;
    }
    push(0);
    status[0] = 2;
    while(Top > -1){
        int current = pop();
        printf("%c ",list[current]->data);
        status[current] = 3;

    struct node *ptr = list[current]->next;
        while(ptr != NULL){
            for(int i=0; i<n; i++){
                if(V[i] == ptr->data && status[i] == 1){
                    push(i);
                    status[i] = 2;
                 }
            }
            ptr = ptr->next;
        }
    }
}

void BFT(struct node *list[], int status[], char V[]){
    for(int i=0; i<n; i++){
        status[i] = 1;
    }
    enqueue(0);
    status[0] = 2;

    while(!isEmpty()){
        int current = dequeue();
        printf("%c ",list[current]->data);
        status[current] = 3;

        struct node *ptr = list[current]->next;
        while(ptr != NULL){
            for(int i=0;i<n;i++){
                if(V[i] == ptr->data && status[i] == 1){
                    enqueue(i);
                    status[i] = 2;
                }
            }
            ptr = ptr->next;
        }
    }
}

struct node** AdjacencyList(char V[], int G[][n]){
    struct node **list = (struct node**)malloc(n * sizeof(struct node*));
    for(int i=0; i<n; i++){
        list[i] = createNode(V[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(G[i][j] == 1){
                struct node *ptr = createNode(V[j]);
                ptr->next = list[i]->next;
                list[i]->next = ptr;
            }
        }
    }
    return list;
}

void displayAL(struct node* list[]){
    for(int i=0; i<n; i++){
        printf("[%c]",list[i]->data);
        struct node *ptr = list[i]->next;
        if(ptr == NULL){
            printf("-> NULL");
        }else{
            while(ptr != NULL){
                printf("-> %c",ptr->data);
                ptr = ptr->next;
            }
        }  
        printf("\n");
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
    struct node **list = AdjacencyList(V,G);
    displayAL(list);

    printf("DFS Traversal: ");
    DFT(list,status,V);

    printf("\nBFS Traversal: ");
    BFT(list,status,V);
}
