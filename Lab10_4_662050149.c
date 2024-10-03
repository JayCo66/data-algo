#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Treenode{
    char data;
    int ht;
    struct Treenode *leftChild;
    struct Treenode *rightChild;
    struct Treenode *mother;
}Treenode;

Treenode *Root = NULL;
Treenode *S[20];
int Top = -1;

void push(Treenode *t){
    Top++;
    S[Top] = t;
}

Treenode* pop(){
    Top--;
    return S[Top+1];
}

int max(int a, int b){
    return (a>b) ? a : b;
}

int Height(Treenode *t){
    return (t==NULL) ? 0 : t->ht;
}

void setHeight(Treenode *t){
    if(t != NULL){
        t->ht = 1 + max(Height(t->leftChild), Height(t->rightChild));
    }
}

int balanceFactor(Treenode *t){
    return (t == NULL) ? 0 : Height(t->leftChild) - Height(t->rightChild);
}

Treenode* createNode(char data){
    Treenode *newNode = (Treenode*)malloc(sizeof(Treenode));
    newNode->data = data;
    newNode->ht = 1;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->mother = NULL;
    return newNode;
}

Treenode* LeftRotate(Treenode *t){
    Treenode *y = t->rightChild;
    Treenode *z = y->leftChild;
    y->leftChild = t;
    t->rightChild = z;
    if(t->mother != NULL){
        if(t == t->mother->leftChild){
            t->mother->leftChild = y;
        }else{
            t->mother->rightChild = y;
        }
    }else{
        Root = y;
    }
    y->mother = t->mother;
    t->mother = y;
    if(z != NULL){
        z->mother = t;
    }
    setHeight(t);
    setHeight(y);
    return y;
}

Treenode* RightRotate(Treenode *t){
    Treenode *y = t->leftChild;
    Treenode *z = y->rightChild;
    y->rightChild = t;
    t->leftChild = z;
    if(t->mother != NULL){
        if(t == t->mother->leftChild){
            t->mother->leftChild = y;
        }else{
            t->mother->rightChild = y;
        }
    }else{
        Root = y;
    }
    y->mother = t->mother;
    t->mother = y;
    if(z != NULL){
        z->mother = t;
    }
    setHeight(t);
    setHeight(y);
    return y;
}

void insert_node(char data){
    Treenode *newNode = createNode(data);
    Treenode *fn = NULL;
    Treenode *t = Root;

    while(t != NULL){
        fn = t;
        if(data > t->data){
            push(t);
            t = t->rightChild;
        }else{
            push(t);
            t = t->leftChild;
        }
    }

    if(fn == NULL){
        Root = newNode;
    }else{
        if(data > fn->data){
            fn->rightChild = newNode;
        }else{
            fn->leftChild = newNode;
        }
        newNode->mother = fn;
    }

    while(Top > -1){
        Treenode *pn = pop();
        setHeight(pn);
        if(balanceFactor(pn) > 1){
            if(balanceFactor(pn->leftChild) < 0){
                pn->leftChild = LeftRotate(pn->leftChild);
            }
            pn = RightRotate(pn);
        }else if(balanceFactor(pn) < -1){
            if(balanceFactor(pn->rightChild) > 0){
                pn->rightChild = RightRotate(pn->rightChild);
            }
            pn = LeftRotate(pn);
        }
        setHeight(pn);
    }
}

void find_node(char data){
    Treenode *fn = Root;
    int level = 0;
    while(fn != NULL){
        if(data == fn->data){
            printf("%d", level);
            return;
        }
        if(data > fn->data){
            fn = fn->rightChild;
        }else{
            fn = fn->leftChild;
        }
        level++;
    }
    printf("-1");
}

void inorder(Treenode *r){
    if(r != NULL){
        inorder(r->leftChild);
        printf("%c",r->data);
        inorder(r->rightChild);
    }
}

void preorder(Treenode *r){
    if(r != NULL){
        printf("%c",r->data);
        preorder(r->leftChild);
        preorder(r->rightChild);
    }
}

void postorder(Treenode *r){
    if(r != NULL){
        postorder(r->leftChild);
        postorder(r->rightChild);
        printf("%c",r->data);
    }
}

int main(){
    char input[50];
    fgets(input, sizeof(input), stdin);

    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if(input[i] >= 'A' && input[i] <= 'Z') {
            insert_node(input[i]);
        }else{
            switch (input[i]) {
            case '1':
                find_node(input[++i]);
                break;
            case '2':
                preorder(Root);
                break;
            case '3':
                inorder(Root);
                break;
            case '4':
                postorder(Root);
                break;
            }
        }
    }
    return 0;
}
