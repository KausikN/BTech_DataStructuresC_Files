#include<stdio.h>

//Structs
struct Stack{
    int top;
    int a[200];
    int tt;
};

//prototypes
void transfer(struct Stack *p1, struct Stack *p2);
void push(struct Stack *p1, int x);
int pop(struct Stack *p1, struct Stack *p2);
void print(struct Stack s);
int isFull(struct Stack s);
int isEmpty(struct Stack s);

void main(){
    struct Stack s1;
    struct Stack s2;
    s1.top=-1;
    s2.top=-1;
    s1.tt=0;
    s2.tt=0;
    printf("-------------------------Queue with Stack------------------------\n");
    int tempor = 1;
    while(tempor>0){
        printf("What do you want do?\nInsert		-	1\nDelete		-	2\nCheck if Full	-	3\nCheck if Empty	-	4\nExit		-	0\nEnter Option: ");
        scanf("%d",&tempor);
        
        if(tempor==1){
            //Enqueue
            printf("-------------------Insert--------------------\n");
            printf("Enter value: ");
            int val=0;
            scanf("%d",&val);
            push(&s1,val);
            print(s1);
        }
        
        if(tempor==2){
            //Dequeue
            printf("--------------------Delete---------------------\n");
            int v = pop(&s1,&s2);
            if(v!=-555){
                printf("Value deleted: %d\n",v);
                print(s1);
            }
            
        }
    
        if(tempor==3){
            //IsFull
            int fl = isFull(s1);
            if(fl==1)printf("\nThe Queue is Full.\n\n");
            if(fl==0)printf("\nThe Queue is not Full.\n\n");
        }
    
        if(tempor==4){
            //IsEmpty
            int fl2 = isEmpty(s1);
            if(fl2==1)printf("\nThe Queue is Empty.\n\n");
            if(fl2==0)printf("\nThe Queue is not Empty.\n\n");
        }
        
        printf("\n-------------------------------------\n\n");
    }
}

void transfer(struct Stack *p1, struct Stack *p2){
    if(p1->top+p2->top>99)printf("\nNot possible.\n\n");
    else {
        int i=p2->top;
        for(;i>-1;i--){
            p1->top++;
            p1->a[p1->top] = p2->a[p2->top];
            p2->top--;
        }
        p1->top = p1->top - p2->tt;
    }
}

void push(struct Stack *p1, int x){
    if(p1->top>98)printf("\nNot possible.\n\n");
    else {
        p1->top++;
        p1->a[p1->top] = x;
    }
}

int pop(struct Stack *p1, struct Stack *p2){
    int temp = -555;
    if(p1->top==-1)printf("\nCannot delete.\n\n");
    else if(p1->top==p1->tt){
        p1->top=-1;
        p1->tt=0;
    }
    else {
        transfer(p2,p1);
        p1->tt++;
        p1->top = p1->top + p1->tt;
        temp = p2->a[p2->top];
        p2->top--;
        transfer(p1,p2);
    }
    return temp;
}

void print(struct Stack s){
    if(s.top==-1)printf("\nNo elements.\n\n");
    else {
        printf("Elements in Queue-Stack are, \n");
        for(int i=s.tt;i<s.top+1;i++){
            printf("Element %d: %d\n",i,s.a[i]);
        }
    }
}

int isFull(struct Stack s){
    if(s.top==199)return 1;
    else return 0;
}
int isEmpty(struct Stack s){
    if(s.top==-1)return 1;
    else return 0;
}