#include<stdio.h>
int main()
{
    int i, j;
    for(i=0; i<8; i++)
    {
        for(j=i+1; j<=8; j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
}
