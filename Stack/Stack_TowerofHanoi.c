#include<stdio.h>
#include<stdlib.h>

//Structs
struct node{
    int x;
    struct node *nptr;
};

//Prototypes
void push(int x,int ch);
int pop(int ch);
void eval(int n);

struct node *top1 = NULL;
struct node *top2 = NULL;
struct node *top3 = NULL;
struct node *a = NULL;
int av,vav;

void main(){
    printf("------------------Towers of Hanoi--------------------\n");	
    printf("Enter number of discs: ");
    int n;
    scanf("%d",&n);
    if(n<1)printf("Invalid number of discs.\n");
    else {
        av=1;
        vav=1;
        eval(n);
    }
    printf("\n-------------------------------------\n\n");
}

//Functions
void push(int x, int ch){
    struct node *temp = malloc(sizeof(struct node));
    struct node *top;
    if(ch==1)top=top1;
    if(ch==2)top=top2;
    if(ch==3)top=top3;
    else printf("\n\n\n!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!\n\n\n");
    if(temp==NULL)printf("No memory.\n");
    else {
        if(top==NULL){
            top=temp;
            temp->x = x;
            temp->nptr = NULL;
        }
        else {
            temp->x = x;
            temp->nptr = top;
            top = temp;
        }
    }
}

int pop(int ch){
    struct node *top;
    if(ch==1)top=top1;
    if(ch==2)top=top2;
    if(ch==3)top=top3;
    else printf("\n\n\n!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!\n\n\n");
    int t=top->x;
    if(top->nptr==NULL){
        top=NULL;
    }
    else {
        top=top->nptr;
    }
    return t;
}

void eval(int n){
    for(int i=1;i<av+1;i++){
        
    }
}