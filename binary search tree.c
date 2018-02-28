#include<stdio.h>
#include<stdlib.h>
int top=-1;
struct node {
   int data;
   struct node *leftChild;
   struct node *rightChild;
}*root=NULL;
struct node*stack[20];

void push(struct node*item){
stack[++top]=item;}

struct node*pop(){
return(stack[top--]);
}
struct node* search(int data){
   struct node *current = root;
   printf("Visiting elements: ");

   while(current->data != data){

      if(current != NULL) {
         printf("%d ",current->data);

         //go to left tree
         if(current->data > data){
            current = current->leftChild;
         }//else go to right tree
         else {
            current = current->rightChild;
         }

         //not found
         if(current == NULL){
            return NULL;
         }
      }
   }
   return current;
}
void insert(int data) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   //if tree is empty
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;

      while(1) {
         parent = current;

         //go to left of the tree
         if(data < parent->data) {
            current = current->leftChild;
            //insert to the left

            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }//go to right of the tree
         else {
            current = current->rightChild;

            //insert to the right
            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }
   }
}
void display(struct node*ptr){
    push(NULL);
    push(ptr);

        while (top != NULL)
    {
        while (ptr != NULL)
        {
            push(ptr);
            ptr = ptr->leftChild;}

        if (top != NULL && ptr == NULL)
        {
            ptr = pop();
            printf("%d",ptr->data);
            ptr = ptr->rightChild;
        }
    }

}
void main(){
int choice=1;
int data;
do{printf("enter the data:");
scanf("%d",&data);
search(data);
insert(data);
printf("press 1 to continue;");
scanf("%d",&choice);}while(choice==1);
display(root);}
