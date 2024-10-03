#include <stdio.h>
#include <string.h>

int Top = -1;
char S[100];

void push(char data){
    if(Top<99){
        Top++;
        S[Top] = data;
    }
}

char pop(){
    char data = '0';
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
        if(input[i] == '('){
            push(input[i]);
        }else if(input[i] == ')'){
            while(Top > -1&& S[Top] != '('){
                printf("%c",pop());
            }
            pop();
        }else if(input[i] == '^'){
            while(Top > -1&& S[Top] == '^'){
                printf("%c",pop());
            }
            push(input[i]);
        }else if(input[i] == '*'||input[i] == '/'){
            while(Top > -1&&(S[Top] == '^'||S[Top] == '*'||S[Top] == '/')){
                printf("%c",pop());
            }
            push(input[i]);
        }else if(input[i] == '+'||input[i] == '-'){
            while(Top > -1&&(S[Top] == '^'||S[Top] == '*'||S[Top] == '/'||S[Top] == '+'||S[Top] == '-')){
                printf("%c",pop());
            }
            push(input[i]);
        }else
            printf("%c",input[i]);
    }
    while(Top > -1){
        printf("%c",pop());
    }

return 0;
}
