#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int data;
    struct node *nptr;
};

void add(int y);
int evaluate(int x,int deg);

struct node *hptr = NULL;

void main(){
    printf("---------------------------Polynomial-----------------------------\n");
    printf("Enter Degree: ");
    int deg;
    scanf("%d",&deg);
    int i=0,tt;
    for(i=0;i<deg+1;i++){
        printf("Enter coefficient of x%d: ",deg-i);
        scanf("%d",&tt);
        add(tt);
    }
    printf("Enter value of x: ");
    int x;
    scanf("%d",&x);
    evaluate(x,deg);
}

void add(int y){
    struct node *temp = malloc(sizeof(struct node));
    if(hptr==NULL){
        hptr=temp;
        temp->data = y;
    }
    else {
        struct node *tmp = hptr;
        while(tmp->nptr != NULL){
            tmp=tmp->nptr;
        }
        tmp->nptr = temp;
        temp->nptr=NULL;
        temp->data = y;
    }
}

int evaluate(int x,int deg){
    int ans=0,i=0;
    struct node *tmp = hptr;
    while(tmp != NULL){
        ans = ans + (tmp->data * pow(x,deg-i));
        tmp=tmp->nptr;
        i++;
    }
    printf("The value is %d\n",ans);	
}