#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
}*start=NULL;


void create()
{
char ch;
 do
 {
  struct node *new_node,*current;

  new_node=(struct node *)malloc(sizeof(struct node));

  printf("nEnter the data : ");
  scanf("%d",&new_node->data);
  new_node->next=NULL;

  if(start==NULL)
  {
  start=new_node;
  current=new_node;
  }
  else
  {
  current->next=new_node;
  current=new_node;
  }

 printf("nDo you want to create another : ");
 ch=getche();

 }while(ch!='n');
}


void display()
{
struct node *new_node;
 printf("The Linked List : n");
 new_node=start;
 while(new_node!=NULL)
   {
   printf("%d--->",new_node->data);
   new_node=new_node->next;
   }
  printf("NULL");
}

void del_beg()
{
struct node *temp;


temp = start;
start = start->next;
temp->next=NULL;
free(temp);
printf("nThe Element deleted Successfully ");
}
void main()
{
create();
display();
del_beg();
}
