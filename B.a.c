/*Code for creating doubly linked list and displaying it.
 Pass the values of linked list in array
 */
#include <stdio.h>
#include <stdlib.h>
struct Node  // creating node
{
 struct Node *prev;// linking to previous data
 int data;  // storing data
 struct Node *next;  // linking to next data
}*head=NULL;   // creating/assigning head to null
void create(int a[],int n)
{
 int i;
 struct Node *temp,*last;
 head=(struct Node *)malloc(sizeof(struct Node));
 head->data=a[0];
 head->next=NULL;
 last=head;

 for(i=1;i<n;i++)
 {
 temp=(struct Node*)malloc(sizeof(struct Node));
 temp->data=a[i];
 temp->next=last->next;
 temp->prev=last;
 last->next=temp;
 last=temp;
 }
}

void print(struct Node *t) // displaying array
{
 while(t!=NULL)
 {
 printf("%d ",t->data);
 t=t->next;
 }
 printf("\n");
}

int main()
{
 int n,i;
 printf("Enter the size of linked list\n");
 scanf("%d",&n);
 int a[n];
 printf("\nEnter the elements to be entered\n");
 for(i=0;i<n;i++)
    scanf("%d",&a[i]);

 create(a,n);

 print(head);

 return 0;
}

