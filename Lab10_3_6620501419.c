#include <stdio.h>
#include <stdlib.h>

struct Treenode {
    int data, ht;
    struct Treenode *leftChild, *rightChild;
    struct Treenode *mother;
};

struct Treenode *Root = NULL;
struct Treenode *pn = NULL;
struct Treenode *S[20];
int Top = -1;

void push(struct Treenode *t) {
    Top++;
    S[Top] = t;
}

struct Treenode* pop() {
    Top--;
    return S[Top+1];
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int Height(struct Treenode *x) {
    return (x == NULL) ? 0 : x->ht;
}

struct Treenode* createNode(int data) {
    struct Treenode *new_node = (struct Treenode*)malloc(sizeof(struct Treenode));
    new_node->data = data;
    new_node->ht = 1;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    new_node->mother = NULL;
    return new_node;
}

int balanceFactor(struct Treenode *A){

    return Height(A->leftChild) - Height(A->rightChild);
}

void setHeight(struct Treenode *A){
    if(A != NULL){
        A->ht = 1+(max(Height(A->leftChild),Height(A->rightChild)));
    }
}

struct Treenode* leftRotate(struct Treenode *x) {
    struct Treenode *y = x->rightChild;
    struct Treenode *z = y->leftChild;
    y->leftChild = x;
    x->rightChild = z;

    if(x->mother != NULL){
        if(x == x->mother->leftChild){
            x->mother->leftChild = y;
        }else{
            x->mother->rightChild = y;
        }
    }else{
        Root = y;
    }
    y->mother = x->mother;
    x->mother = y;

    if(z!= NULL)
        z->mother = x;
    
    printf("Left Rotate at Node: %d\n", x->data);
    
    setHeight(x);
    setHeight(y);

    return y;
}

struct Treenode* rightRotate(struct Treenode *x) {
    struct Treenode *y = x->leftChild;
    struct Treenode *z = y->rightChild;
    y->rightChild = x;
    x->leftChild = z;
    if(x->mother != NULL){
        if(x == x->mother->leftChild){
            x->mother->leftChild = y;
        }else{
            x->mother->rightChild = y;
        }
    }else{
        Root = y;
    }
    y->mother = x->mother;
    x->mother = y;

    if(z!= NULL)
        z->mother = x;

    printf("Right Rotate at Node: %d\n", x->data);

    setHeight(x);
    setHeight(y);

    return y;
}

void Tree_insert(int data) {
    struct Treenode *nn = createNode(data);
    struct Treenode *fn = NULL;
    struct Treenode *t = Root;

    while (t != NULL) {
        fn = t;
        if (data < t->data) {
            push(t);
            t = t->leftChild;
        } else {
            push(t);
            t = t->rightChild;
        }
    }

    if (fn == NULL) {
        Root = nn;
    } else {
        if (nn->data < fn->data) {
            fn->leftChild = nn;
        } else {
            fn->rightChild = nn;
        }
        nn->mother = fn;
    }

    while (Top > -1) {
        pn = pop();
        pn->ht = 1 + max(Height(pn->leftChild), Height(pn->rightChild));

        if (balanceFactor(pn) > 1) {
            if (balanceFactor(pn->leftChild) >= 0){
                pn = rightRotate(pn);
            } else {
                printf("Left-Right Double Rotate\n");
                pn->leftChild = leftRotate(pn->leftChild);
                pn = rightRotate(pn);
            }
        } else if (balanceFactor(pn) < -1) {
            if (balanceFactor(pn->rightChild) <= 0){
                    pn = leftRotate(pn);
            } else {
                printf("Right-Left Double Rotate\n");
                pn->rightChild = rightRotate(pn->rightChild);
                pn = leftRotate(pn);
            }
        }        
    }
}

void inorder(struct Treenode *r) {
    if (r != NULL) {
        inorder(r->leftChild);
        printf("%d(Bf=%d)", r->data, balanceFactor(r));
        inorder(r->rightChild);
    }
}

int main() {
    int input;
    do {
        printf("Insert node: ");
        scanf("%d", &input);
        if (input >= 0) {
            Tree_insert(input);
        }
    } while (input >= 0);

    inorder(Root);

    return 0;
}