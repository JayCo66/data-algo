#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    
    char input[100];
    char postfix[100];
    int TopPS = -1;
    char S[100];
    int Top = -1;
    
    printf("Enter infix:");
    scanf("%s",input);
    
    int len = strlen(input);
    for(int i=0;i<len;i++){
        if(input[i] == '('){
            Top++;
            S[Top] = input[i];
        }else if(input[i] == ')'){
            while(Top > -1&& S[Top] != '('){
                TopPS++;
                postfix[TopPS] = S[Top];
                Top--;
            }
            Top--;
        }else if(input[i] == '^'){
            while(Top > -1&& S[Top] == '^'){
                TopPS++;
                postfix[TopPS] = S[Top];
                Top--;
            }
            Top++;
            S[Top] = input[i];
        }else if(input[i] == '*'||input[i] == '/'){
            while(Top > -1&&(S[Top] == '^'||S[Top] == '*'||S[Top] == '/')){
                TopPS++;
                postfix[TopPS] = S[Top];
                Top--;
            }
            Top++;
            S[Top] = input[i];
        }else if(input[i] == '+'||input[i] == '-'){
            while(Top > -1&&(S[Top] == '^'||S[Top] == '*'||S[Top] =='/'||S[Top]== '+'||S[Top] == '-')){
                TopPS++;
                postfix[TopPS] = S[Top];
                Top--;
            }
            Top++;
            S[Top] = input[i];
        }else{
            TopPS++;
            postfix[TopPS] = input[i];
        }
    }
    while(Top>-1){
        TopPS++;
        postfix[TopPS] = S[Top];
        Top--;
    }
    
    printf("postfix:");
    int PFlen = strlen(postfix);
    for(int i=0; i<PFlen; i++){
        printf("%c",postfix[i]);
    }
    printf("\n");

    struct monomial{
    	int value;
	    char variable;
    };
    struct monomial Eq[100];
    int TopM = -1;
    
    for(int i=0; i<PFlen; i++){
        if((postfix[i] >= 'a' && postfix[i] <= 'z')||(postfix[i] >= 'A' && postfix[i] <= 'Z')){
	        int check = 1;
	        for(int j=0;j<=TopM;j++){
	            if(postfix[i] == Eq[j].variable)
	                check = 0;
	        }
	        if(check){
	            printf("Enter value of %c:",postfix[i]);
                TopM++;
                int data;
                scanf("%d",&data);
                Eq[TopM].value = data;
                Eq[TopM].variable = postfix[i];
	        }
        }
    }
    int TopC = -1;
    int SCal[100];
    
    for(int i=0;i<PFlen;i++){
        if((postfix[i] >= 'a' && postfix[i] <= 'z')||(postfix[i] >= 'A' && postfix[i] <= 'Z')){
            for(int j=0;j<=TopM;j++){
                if(postfix[i] == Eq[j].variable){
                    TopC++;
                    SCal[TopC] = Eq[j].value;
                    break;
                }
            }
        }else if(postfix[i] == '+'||postfix[i] == '-'||postfix[i] == '*'||postfix[i] == '/'||postfix[i] == '^'){
            int op1 = SCal[TopC];
            TopC--;
            int op2 = SCal[TopC];
            TopC--;

            switch (postfix[i]){

            case '+':
                TopC++;
                SCal[TopC] = op2+op1;
                break;

            case '-':
                TopC++;
                SCal[TopC] = op2-op1;
                break;

            case '*':
                TopC++;
                SCal[TopC] = op2*op1;
                break;

            case '/':
                TopC++;
                SCal[TopC] = op2/op1;
                break;

            case '^':
                TopC++;
                SCal[TopC] = (pow(op2,op1));
                break;
            }
        }
    }
    printf("Result= %d",SCal[TopC]);
    
    return 0;
}