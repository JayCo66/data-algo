#include <stdio.h>
#include <stdlib.h>
struct Treenode {
 int data,ht;
 struct Treenode *leftChild,*rightChild;
 struct Treenode *mother;
};
struct Treenode *Root;
struct Treenode *S[20];
int Top = -1;

void push(struct Treenode *t){
    Top++;
    S[Top] = t;
}
struct Treenode* pop(){
    struct Treenode *rt;
    rt = S[Top];
    Top--;

    return rt;
}

int max(int a,int b){
    return (a>b)? a:b;
}

int Height(struct Treenode *x){

    return (x == NULL)? 0 : x->ht;
}

struct Treenode* createNode(int data){
    struct Treenode *new_node = (struct Treenode*)malloc(sizeof(struct Treenode));
    new_node->data = data;
    new_node->ht = 1;
    new_node->leftChild =NULL;
    new_node->rightChild=NULL;
    new_node->mother=NULL;
    return new_node;
}

void Tree_insert(int data) {
    struct Treenode *nn = createNode(data);
    struct Treenode *fn = NULL;
    struct Treenode *t = Root;

    while(t != NULL)
    {
        fn = t;
        if(data < t->data)
        {
            push(t);
            t = t->leftChild;
        }else
        {
            push(t);
            t = t->rightChild;
        }
    }
        if(fn == NULL)
        {
            Root = nn;
        }else
        {
            if(nn->data < fn->data){
                fn->leftChild = nn;
                nn->mother = fn;
            }
            else{
                fn->rightChild = nn;
                nn->mother = fn;
            }
        }

        while(Top>-1){
            struct Treenode *pn = pop();
            pn->ht = 1+max(Height(pn->leftChild),Height(pn->rightChild));
        }
}

int checkAVL (struct Treenode *r){
    int check = 1;
    if(r != NULL){
        int BF = Height(r->leftChild) - Height(r->rightChild);
        if(BF > 1 || BF < -1){
                check = 0;
                return check;
        }else{
            check = checkAVL(r->leftChild);
            if(check == 0){
                return check;
            }
            check = checkAVL(r->rightChild);
            if(check == 0){
                return check;
            }
        }
    }
    return check;
}

int main()  {
    int input;
    while(input >= 0){
        scanf("%d",&input);
        Tree_insert(input);
    }
    if(checkAVL(Root)){
        printf("an AVL Tree");
    }else
        printf("Not an AVL Tree");

    return 0;
}
