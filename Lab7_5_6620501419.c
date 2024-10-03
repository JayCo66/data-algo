#include <stdio.h>
#include <string.h>
#define maxsize 15

int main()
{
    char doc[maxsize];
    int TopDoc = -1;
    char redoS[maxsize];
    int TopredoS = -1;

    char input[maxsize];
    char A;

    do{
        scanf("%s",input);

        if(!strcmp(input,"WRITE"))
        {
            scanf(" %c",&A);
            TopDoc++;
            doc[TopDoc] = A;
        }else if (!strcmp(input,"UNDO"))
        {
            char data;
            data = doc[TopDoc];
            TopDoc--;
            TopredoS++;
            redoS[TopredoS] = data;
        }else if (!strcmp(input,"REDO"))
        {
            char data;
            data = redoS[TopredoS];
            TopredoS--;
            TopDoc++;
            doc[TopDoc] = data;
        }else if (!strcmp(input,"READ"))
        {
            if(TopDoc == -1){
                printf("Blank document");
            }else{
               for(int i=0;i<=TopDoc;i++){
                    printf("%c", doc[i]);
                } 
            }
            printf("\n");
        }
    }while(strcmp(input,"END"));

    return 0;
}
