#include <stdio.h>
#define maxsize 10
#include <stdlib.h>

struct Q{
    int data;
    struct Q *next;
};

struct Q *Front = NULL, *Rear = NULL;

void enqueue(int);
int dequeue();
void displayQ();

int main()
{
    int i,n;
    for(i=1;i<1000;i*=2)
        enqueue(i);
    displayQ();
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        dequeue();
    displayQ();
    for(i=10;i>=1;i/=2)
        enqueue(i);
    displayQ();
}

void enqueue(int data)
{
    struct Q *newNode;
    newNode = (struct Q*)malloc(sizeof(struct Q));
    newNode->data = data;
    newNode->next = NULL;

    if(Front == NULL){
        Front = Rear = newNode;
    }else{
        Rear->next = newNode;
        Rear = newNode;
    }
}

int dequeue()
{
    struct Q *ptr;
    if(Front == NULL){
        printf("\nQueue is Empty\n");
        return -1;
    }else
    {
        ptr = Front;
        Front = Front->next;
        ptr->next = NULL;
        return ptr->data;
    }
}

void displayQ()
{
    int i;
    if(Front == NULL)
        printf("\nQueue is Empty\n");
    else
    {
        struct Q *ptr = Front;
        printf("front[");
        while(ptr != NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        printf("rear]\n");
    }
}
