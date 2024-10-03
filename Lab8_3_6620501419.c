#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Treenode {
    char data;
    struct Treenode *leftChild;
    struct Treenode *rightChild;
};

struct Treenode *Root;

struct Treenode* createNode(char data) {
    struct Treenode* newNode;
    newNode = (struct Treenode*)malloc(sizeof(struct Treenode));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

struct Treenode* createExpressionTree(char prefix[]) {
    int Top = -1;
    struct Treenode *S[50];
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        if (prefix[i] >= '0' && prefix[i] <= '9') {
            Top++;
            S[Top] = createNode(prefix[i]);
        } else {
            struct Treenode *op1 = S[Top];
            Top--;
            struct Treenode *op2 = S[Top];
            Top--;

            Top++;
            S[Top] = createNode(prefix[i]);
            S[Top]->leftChild = op1;
            S[Top]->rightChild = op2;
        }
    }
    struct Treenode *exTree = S[Top];
    Top--;
    return exTree;
}

int eval(struct Treenode *Root) {
    if (Root == NULL) {
        return 0;
    }

    if (Root->data >= '0' && Root->data <= '9') {
        return Root->data - '0';
    } else {
        int x = eval(Root->leftChild);
        int y = eval(Root->rightChild);
        char opt = Root->data;

        switch (opt) {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            case '/':
                return x / y;
            case '^':
                return pow(x, y);
            default:
                return 0;
        }
    }
}

void infix(struct Treenode *Root) {
    if (Root->data >= '0' && Root->data <= '9') {
        printf("%c", Root->data);
    } else {
        printf("(");
        infix(Root->leftChild);
        printf("%c", Root->data);
        infix(Root->rightChild);
        printf(")");
    }
}

int main() {
    char prefix[50];
    scanf("%s", prefix);

    struct Treenode *exTree = createExpressionTree(prefix);
    infix(exTree);
    int value = eval(exTree);
    printf("=%d\n", value);

    return 0;
}