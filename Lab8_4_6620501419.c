#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Treenode {
    int opr;
    char opt;
    struct Treenode *leftChild;
    struct Treenode *rightChild;
};

struct Treenode* createNode(int opr, char opt) {
    struct Treenode* newNode = (struct Treenode*)malloc(sizeof(struct Treenode));
    newNode->opr = opr;
    newNode->opt = opt;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

int stringToInt(char num[]) {
    int len = strlen(num);
    int value = 0;

    for (int i = 0; i < len; i++) {
        value = value * 10 + (num[i] - '0');
    }
    return value;
}

struct Treenode* createExpressionTree(char postfix[]) {
    char num[100];
    int numIndex = 0;
    int Top = -1;
    struct Treenode *S[100];
    int len = strlen(postfix);

    for (int i = 0; i < len; i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            numIndex = 0;
            while (postfix[i] != ' ' && postfix[i] != '\0') {
                num[numIndex++] = postfix[i];
                i++;
            }
            num[numIndex] = '\0';
            Top++;
            S[Top] = createNode(stringToInt(num), ' ');
        } else if (postfix[i] == ' ') {
            continue;
        } else {
            struct Treenode *op2 = S[Top];
            Top--;
            struct Treenode *op1 = S[Top];
            Top--;

            Top++;
            S[Top] = createNode(0, postfix[i]);
            S[Top]->leftChild = op1;
            S[Top]->rightChild = op2;
        }
    }
    return S[Top];
}

int eval(struct Treenode *Root) {
    if (Root == NULL) {
        return 0;
    }
    if (Root->opt == ' ') {
        return Root->opr;
    } else {
        int x = eval(Root->leftChild);
        int y = eval(Root->rightChild);
        switch (Root->opt) {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            case '/':
                return x / y;
            default:
                return 0;
        }
    }
}

void infix(struct Treenode *Root) {
    if (Root == NULL) return;

    if (Root->opt == ' ') {
        printf("%d", Root->opr);
    } else {
        printf("(");
        infix(Root->leftChild);
        printf("%c", Root->opt);
        infix(Root->rightChild);
        printf(")");
    }
}

int main() {
    char postfix[100];
    fgets(postfix, sizeof(postfix), stdin);

    postfix[strcspn(postfix, "\n")] = 0;

    struct Treenode *exTree = createExpressionTree(postfix);
    infix(exTree);
    int value = eval(exTree);
    printf("=%d\n", value);

    return 0;
}