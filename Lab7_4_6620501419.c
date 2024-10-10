#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

typedef struct node{
	char data;
	struct node *next;
}node;

	node*Top=NULL,*newnode;

int palindrome(char []);
void push(char);
int pop(char);

int main(){
	char S[101],S1[101],S2[101];
	int i=0,l,item;
	char ch;
	
	scanf("%s",S);
	
	while(S[i]!='\0'){
	ch = S[i];
	S[i] = toupper(ch);
	i++;
	}
	
	 l = strlen(S);
	
	for(i=0;i<l/2;i++){
		S1[i]=S[i];
	}
	
	if(l%2!= 0 )
		l++;

	for(i=l/2;i<strlen(S);i++){
		S2[i]=S[i];
	}
	

	if(palindrome(S)){
	printf("No");
	return 0;
	}	

	if(palindrome(S1) && palindrome(S2)){
	printf("Palindrome");
	return 0;
	}

	printf("Double Palindrome");
	
}

int palindrome(char S[]){
	
	int i,l,item;
	
	l = strlen(S);
	
	for(i=0;i<l/2;i++){
		push(S[i]);
	}
	
	if(l%2!= 0)
	l++;

	for(i=l/2;i<strlen(S);i++){
		item = pop(S[i]);
		if(item==-1)
			return -1;
	} 
	return 0;
}

void push(char data){
	
	newnode = (node*)malloc(sizeof(node*));
	newnode->data = data;
	newnode->next = Top;
	Top = newnode;
}

int pop(char data){
	node *ptr=Top;
	if(data==Top->data){
		Top = Top->next;
		free(ptr);
		return 0;
	}
	return -1;	
}