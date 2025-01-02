#include <stdio.h>
#include <stdlib.h>

struct Treenode{
    int data;
    struct Treenode *leftChild;
    struct Treenode *rightChild;
};

struct Treenode *Root = NULL;

struct Treenode* createNode(int data){
    struct Treenode *newNode = (struct Treenode*)malloc(sizeof(struct Treenode));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    return newNode;
}

void insertTree(int data){
    struct Treenode *x = createNode(data);
    struct Treenode *y = Root;
    struct Treenode *t = NULL;

    while(y != NULL){
        t = y;
        if(data > y->data){
            y = y->rightChild;
        }else{
            y = y->leftChild;
        }
    }

    if(t!=NULL){
        if(data > t->data){
            t->rightChild = x;
        }else{
            t->leftChild = x;
        }
    }else{
        Root = x;
    }
}




int main(){

}