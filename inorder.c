#include<stdio.h>
#include<stdlib.h>
int top=-1;

struct node{
int data;
struct node*left;
struct node*right;}*root=NULL;


struct node*stack[20];

void push(struct node*item){
stack[++top]=item;}

struct node*pop(){
return(stack[top--]);
}

void create(){
struct node*temp,*ptr;
int ch,flag=1;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the info");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;
if(root==NULL){
root=temp;}
else{
ptr=root;
while(flag==1){
printf("Press 1 to insert in left and 2 to insert in right");
scanf("%d",&ch);
if(ch==1){
if(ptr->left==NULL){
ptr->left=temp;flag=2;exit;}
else
ptr=ptr->left;}
if(ch==2){
if(ptr->right==NULL){
ptr->right=temp;flag=2;exit;}
else
ptr=ptr->right;}}}}

void display(struct node*ptr){
    push(ptr);

        while (top != NULL)
    {
        while (ptr != NULL)
        {
            push(ptr);
            ptr = ptr->left;}

        if (top != NULL && ptr == NULL)
        {
            ptr = pop();
            printf("%d",ptr->data);
            ptr = ptr->right;
        }
    }

}
void main(){
int choice=1;
do{
create();
printf("press 1 to continue;");
scanf("%d",&choice);}while(choice==1);
display(root);}
