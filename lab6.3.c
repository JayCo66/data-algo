#include <stdio.h>
#include <string.h> 
#define maxsize  10 

char Q[maxsize]={""}; 
int Front= -1;
int Rear= -1; 
int size=0;

void enqueue (char);
void dequeue (int);
void displayFR ();

int main()
{
    char input[20];
    
    scanf("%s",input);

    for(int j=0;j<strlen(input);j++){
        if(input[j]>= 'A' && input[j] <= 'Z'){
            enqueue(input[j]);
        }else if(input[j] >= '1' && input[j] <= '9'){
            dequeue(input[j]-'0');
        }else if(input[j] == '0'){
            displayFR();
        }
    }
    return 0;
}

void enqueue (char A){
    if(size == maxsize){
        printf("!");
    }else{
        if(Front == -1 || Rear == -1){
            Front = Rear = 0;
        }else{
            Rear = (Rear + 1)%maxsize;
        }
        Q[Rear] = A;
        size++;
    }
}

void dequeue (int A){

    for(int i=0;i<A;i++){
        if(size == 0){
            printf("!");
        }else{
            printf("%c",Q[Front]);
            Front = (Front+1)%maxsize;
            size--;
        }
    }
}

void displayFR(){
    printf("%d%d",Front,Rear);
}

