#include<stdio.h>

//Structs
struct Queue
{
  	int a[200];
  	int rear;
  	int front;
};

//prototypes
void transfer(struct Stack *p1, struct Stack *p2);
void push(struct Stack *p1, int x);
int pop(struct Stack *p1, struct Stack *p2);
void print(struct Stack s);
int isFull(struct Stack s);
int isEmpty(struct Stack s);

void main(){
	struct Queue s1;
	struct Queue s2;
	s1.front=-1;
	s2.front=-1;
	s1.rear=-1;
	s2.rear=-1;
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

   
