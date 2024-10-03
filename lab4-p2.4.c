#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct doublyNode {
    int data;
    struct doublyNode *next;
    struct doublyNode *prev;
} Dnode;

node *head = NULL;

node* newNode(int v) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = v;
    newnode->next = NULL;
    return newnode;
}

bool isCircular(node *h) {
    node *ptr = h;
    while (1) {
        ptr = ptr->next;
        if (ptr == NULL)
            return 0;
        else if (ptr == h)
            return 1;
    }
}

Dnode* newDNode(int v) {
    Dnode* newNode = (Dnode*)malloc(sizeof(Dnode));
    newNode->data = v;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Dnode *headDnode = NULL;

void doublyMaker() {
    if (head == NULL) return;

    headDnode = newDNode(head->data);
    node *Sptr = head->next;
    Dnode *Dptr = headDnode;

    while (Sptr != NULL) {
        Dnode *newD = newDNode(Sptr->data);
        Dptr->next = newD;
        newD->prev = Dptr;
        Dptr = newD;
        Sptr = Sptr->next;
    }
}

void DisplayDLLReverse() {
    if (headDnode == NULL) return;

    Dnode *ptr = headDnode;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    node *tail = NULL;

    for (int i = 1; i <= n; i++) {
        node *new_node = newNode(i);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    doublyMaker();
    DisplayDLLReverse();

    return 0;
}
