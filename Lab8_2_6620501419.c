#include <stdio.h>
#include <stdlib.h>

struct Treenode {
 char data;
 struct Treenode *leftChild;
 struct Treenode *rightChild;
};
struct Treenode *Root;

struct Treenode* createNode(char data)
{
    struct Treenode* newNode;
    newNode = (struct Treenode*)malloc(sizeof(struct Treenode));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    return newNode;
}
void SetLeft(struct Treenode* pn, char data)
{
    struct Treenode* newNode = createNode(data);

    if(pn->leftChild == NULL){
        pn->leftChild = newNode;
    }else
        printf("Node In-used");
}
void SetRight(struct Treenode* pn, char data)
{
    struct Treenode* newNode = createNode(data);

    if(pn->rightChild == NULL){
        pn->rightChild = newNode;
    }else
        printf("Node In-used");

}
void preorder(struct Treenode *pn)
{
    if(pn != NULL)
    {
        printf(" %c ",pn->data);
        preorder(pn->leftChild);
        preorder(pn->rightChild);
    }
}

void postorder(struct Treenode *pn)
{
    if(pn != NULL)
    {
        postorder(pn->leftChild);
        postorder(pn->rightChild);
        printf(" %c ",pn->data);
    }
}

int xxx(struct Treenode* r)
{
    if(r == NULL)
        return 0;
    return 1 + xxx(r->leftChild) + xxx(r->rightChild);
}

int main()
{
   struct Treenode *pn,*tnode;

  tnode=createNode('*');
  if(Root == NULL)
    Root=tnode;

  SetLeft(Root,'+');
  SetRight(Root,'-');

  pn=Root->leftChild;
  SetLeft(pn,'*');
  SetRight(pn,'/');

  pn=pn->leftChild;
  SetLeft(pn,'A');
  SetRight(pn,'B');

  pn=Root->leftChild->rightChild;
  SetLeft(pn,'C');
  SetRight(pn,'D');

  pn=Root->rightChild;
  SetLeft(pn,'E');
  SetRight(pn,'F');

  printf("Prefix: ");
  preorder(Root);
  printf("\n");

  printf("Postfix: ");
  postorder(Root);
  printf("\n");

  free(tnode);
  free(pn);

  return 0;
}
