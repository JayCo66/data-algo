#include <stdio.h>
#include <stdlib.h>

struct Treenode {
 int data;
 struct Treenode *leftChild,*rightChild;
 struct Treenode *mother;
};
struct Treenode *Root;

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

struct Treenode* Tree_Find(struct Treenode *pn, int key)
{
    while(pn != NULL){
        if(pn->data == key){
            return pn;
        }else if(pn->data < key){
            pn = pn->rightChild;
        }else
            pn = pn->leftChild;
    }
    return NULL;
}

struct Treenode* FindMin(struct Treenode *Root)
{
    while(Root->leftChild != NULL){
        Root = Root->leftChild;
    }
        return Root;
}

struct Treenode* FindMax(struct Treenode *Root)
{
    while(Root->rightChild != NULL){
        Root = Root->rightChild;
    }
    return Root;
}

void Tree_delete(struct Treenode *Root,int key)
{
    struct Treenode *x = Tree_Find(Root,key);
    if(x == NULL)
        printf("Not found");
    else{
        if(x->leftChild != NULL && x->rightChild != NULL){
            struct Treenode *y = FindMax(x->leftChild);
            x->data = y->data;
            Tree_delete(x->leftChild,y->data);
        }else{
            if(x->leftChild == NULL && x->rightChild == NULL){
                if(x->data > x->mother->data){
                    x->mother->rightChild = NULL;
                }else{
                    x->mother->leftChild = NULL;
                }
            }else if(x->leftChild == NULL || x->rightChild == NULL){
                if(x->rightChild != NULL){
                    struct Treenode *pr = x->rightChild;
                    if(x->data > x->mother->data){
                        x->mother->rightChild = pr;
                        pr->mother = x->mother;
                    }else{
                        x->mother->leftChild = pr;
                        pr->mother = x->mother;
                    }
                }else{
                    struct Treenode *pl = x->leftChild;
                    if(x->data > x->mother->data){
                        x->mother->rightChild = pl;
                        pl->mother = x->mother;
                    }else{
                        x->mother->leftChild = pl;
                        pl->mother = x->mother;
                    }
                }
            }
        }
    }
}

int main()
{
  int a[]={56,26,200,18,28,190,213,12,24,27};
  int i,size;
  size=sizeof(a)/sizeof(a[0]);

  for(i=0;i<size;i++)
        Tree_insert(a[i]);

   printf("Min=%d\n",FindMin(Root)->data);
   printf("Max=%d\n",FindMax(Root)->data);

   struct Treenode *p;
   p=Tree_Find(Root,190);

  if(p!=NULL)
    printf("Found\n");
  else
    printf("Not found\n");

   Tree_delete(Root,190);
   Tree_delete(Root,26);

   Inorder(Root);
}

