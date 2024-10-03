#include <stdio.h>
#include <string.h>
#include <math.h>

int Top = -1;
int S[100];

void push(int data){
    if(Top<99){
        Top++;
        S[Top] = data;
    }
}

char pop(){
    int data = 0;
    if(Top > -1){
        data = S[Top];
        Top--;
    }
    return data;
}

int main(){

    char input[100];
    gets(input);

    int len = strlen(input);

    for(int i=0;i<len;i++){
        if(input[i] >= '1' && input[i] <= '9'){
            push(input[i]-'0');
        }else if(input[i] == '+'||input[i] == '-'||input[i] == '*'||input[i] == '/'||input[i] == '^'){
            int op1 = pop();
            int op2 = pop();

            switch (input[i]){

            case '+':
                push(op2+op1);
                break;

            case '-':
                push(op2-op1);
                break;

            case '*':
                push(op2*op1);
                break;

            case '/':
                push(op2/op1);
                break;

            case '^':
                push(pow(op2,op1));
                break;
            }
        }
    }
    printf("%d",S[Top]);

return 0;
}

