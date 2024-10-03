#include <stdio.h>
#include <stdlib.h>
struct Treenode {
 int data;
 struct Treenode *leftChild,*rightChild;
 struct Treenode *mother;
};
struct Treenode *Root=NULL;

struct Treenode* createNode(int data)
{
    struct Treenode *new_node;
    new_node= (struct Treenode*) malloc(sizeof(struct Treenode));
    new_node->data =data;
    new_node->leftChild =NULL;
    new_node->rightChild=NULL;
    new_node->mother=NULL;
    return new_node;
}


void Tree_insert(int data)
{
    struct Treenode *x = createNode(data);
    struct Treenode *y = NULL;
    struct Treenode *t = Root;
    while(t != NULL)
    {
        y = t;
        if(data < t->data)
        {
            t = t->leftChild;
        }else
        {
            t = t->rightChild;
        }
    }
        if(y == NULL)
        {
            Root = x;
        }else
        {
            if(x->data < y->data){
                y->leftChild = x;
                x->mother = y;
            }
            else{
                y->rightChild = x;
                x->mother = y;
            }
        }
}

void Inorder(struct Treenode *pn)
{
    if(pn != NULL){
        Inorder(pn->leftChild);
        printf("%d ",pn->data);
        Inorder(pn->rightChild);
    }
}


int main()
{
   int i,count=20;
   int num[count];

   srand((unsigned) time(NULL));
   printf("Number before sorting\n");
   for(i=0;i<count;i++)
   {
      num[i]=rand();
      printf("%d ",num[i]);
   }

   for(i=0;i<count;i++)
        Tree_insert(num[i]);

   printf("\nNumber after sorting\n");
   Inorder(Root);

   return 0;
}
