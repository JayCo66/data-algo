#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Treenode {
    char data;
    struct Treenode *leftChild, *rightChild;
    struct Treenode *mother;
};
struct Treenode *Root;

struct Treenode* createNode(char data) {
    struct Treenode *new_node = (struct Treenode*) malloc(sizeof(struct Treenode));
    new_node->data = data;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    new_node->mother = NULL;
    return new_node;
}

void Tree_insert(char data) {
    struct Treenode *x = createNode(data);
    struct Treenode *y = NULL;
    struct Treenode *t = Root;
    while (t != NULL) {
        y = t;
        if (data < t->data) {
            t = t->leftChild;
        } else {
            t = t->rightChild;
        }
    }
    if (y == NULL) {
        Root = x;
    } else {
        if (x->data < y->data) {
            y->leftChild = x;
            x->mother = y;
        } else {
            y->rightChild = x;
            x->mother = y;
        }
    }
}

struct Treenode* Tree_Find(struct Treenode *pn, char key) {
    while (pn != NULL) {
        if (pn->data == key) {
            return pn;
        } else if (pn->data < key) {
            pn = pn->rightChild;
        } else {
            pn = pn->leftChild;
        }
    }
    return NULL;
}

struct Treenode* FindMin(struct Treenode *Root) {
    while (Root->leftChild != NULL) {
        Root = Root->leftChild;
    }
    return Root;
}

struct Treenode* FindMax(struct Treenode *Root) {
    while (Root->rightChild != NULL) {
        Root = Root->rightChild;
    }
    return Root;
}

void Tree_delete(struct Treenode *Root, char key) {
    struct Treenode *x = Tree_Find(Root, key);
    if (x == NULL) {
        printf("Not found");
        return;
    }

    struct Treenode *y;
    if (x->leftChild != NULL && x->rightChild != NULL) {
        y = FindMin(x->rightChild);
        x->data = y->data;
        Tree_delete(x->rightChild, y->data);
    } else {
        struct Treenode *child = (x->leftChild != NULL) ? x->leftChild : x->rightChild;

        if (x->mother == NULL) {
            // If x is the root node
            Root = child;
        } else if (x == x->mother->leftChild) {
            x->mother->leftChild = child;
        } else {
            x->mother->rightChild = child;
        }
        if (child != NULL) {
            child->mother = x->mother;
        }
    }
}

void Inorder(struct Treenode *pn) {
    if (pn != NULL) {
        Inorder(pn->leftChild);
        printf("%c", pn->data);
        Inorder(pn->rightChild);
    }
}

void Preorder(struct Treenode *pn) {
    if (pn != NULL) {
        printf("%c", pn->data);
        Preorder(pn->leftChild);
        Preorder(pn->rightChild);
    }
}

void Postorder(struct Treenode *pn) {
    if (pn != NULL) {
        Postorder(pn->leftChild);
        Postorder(pn->rightChild);
        printf("%c", pn->data);
    }
}

int treeCompraing(struct Treenode *Root, char data) {
    if (Root != NULL) {
        if (Root->data == data) {
            return 0;
        } else if (!treeCompraing(Root->leftChild, data)) {
            return 0;
        } else if (!treeCompraing(Root->rightChild, data)) {
            return 0;
        }
    }
    return 1;
}

void caseOneLevelCheck(char key) {
    struct Treenode *pn = Tree_Find(Root, key);
    if (pn == NULL) {
        printf("-1");
        return;
    }

    int level = 0;
    struct Treenode *current = Root;
    while (current != NULL) {
        if (current->data == key) {
            printf("%d", level);
            return;
        }
        if (key < current->data) {
            current = current->leftChild;
        } else {
            current = current->rightChild;
        }
        level++;
    }
    printf("-1");
}

int main() {
    char input[50];
    fgets(input, sizeof(input), stdin);
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            if (treeCompraing(Root, input[i])) {
                Tree_insert(input[i]);
            }
        } else {
            switch (input[i]) {
                case '0':
                    if (Tree_Find(Root, input[++i]) != NULL) {
                        Tree_delete(Root, input[i]);
                    } else {
                        printf("-1");
                    }
                    break;
                case '1':
                    caseOneLevelCheck(input[++i]);
                    break;
                case '2':
                    Preorder(Root);
                    break;
                case '3':
                    Inorder(Root);
                    break;
                case '4':
                    Postorder(Root);
                    break;
                case '5':
                    printf("%c", FindMin(Root)->data);
                    printf("%c", FindMax(Root)->data);
                    break;
            }
        }
    }
}
