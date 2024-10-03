#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
   int data;
   struct node *next;
};

struct node *head=NULL;

int search_item(int x)
{
    struct node *ptr;
    int count = 1;
    ptr = head;
    while(ptr != NULL)
    {
        if(ptr -> data == x)
        {
            return count;
        }
        count++;
        ptr = ptr->next;
    }
    return -1;
}

void DisplayLL()
{
    struct node *ptr;
    ptr = head;
    while(ptr != NULL)
    {
     printf("%d\t", ptr -> data);
     ptr = ptr -> next;
    }
    printf("\n");
}

/*void DisplayAddressLL()
{
  struct node *ptr;
  ptr = head;
  while(ptr != NULL)
  {
     printf("Node val=%d,add=%X\t ", ptr -> data,ptr);
     printf("Next node add=%X\n",ptr->next);

     ptr = ptr -> next;
  }
}*/

void SortLL(struct node *head)
{
    int swapped;
    struct node* ptr1;
    struct node* lptr = NULL;

    if (head == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1 -> data > ptr1 -> next -> data) {
                int ptr = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = ptr;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}


int main()
{
    int x,n;
    struct node *new_node;
    srand((unsigned) time(NULL));

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        new_node = (struct node*) malloc(sizeof(struct node));
        x=rand()%100 +1;
        new_node->data = x;
        new_node->next = head;
        head = new_node;
    }
    
    DisplayLL();
    SortLL(head);
    DisplayLL();

    int k;
    scanf("%d",&k);

    new_node = (struct node*) malloc(sizeof(struct node));
        new_node->data = k;
        new_node->next = head;
        head = new_node;

    SortLL(head);
    DisplayLL();
}