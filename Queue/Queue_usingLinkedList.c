#include<stdio.h>
#include<stdlib.h>

//Structs
struct node
{
	int x;
	struct node *nptr;
};

//Prototypes
void enqueue(int x);
int dequeue();
void print();
int isFull();
int isEmpty();

//Start
struct node *fptr = NULL;
struct node *rptr = NULL;

void main(){
	printf("--------------------------Queue using LL----------------------------\n");
	int tempor=1;
	while(tempor>0){
		printf("What do you want do?\nEnqueue		-	1\nDequeue		-	2\nCheck if Full		-	3\nCheck if Empty		-	4\nExit			-	0\nEnter Option: ");
		scanf("%d",&tempor);
		
		if(tempor==1){
			//Enqueue
			printf("-------Enqueue--------\n");
			printf("Enter value: ");
			int inp;
			scanf("%d",&inp);
			enqueue(inp);
			print();
		}
		
		if(tempor==2){
			//Dequeue
			if(isEmpty()==0){
				int v = dequeue();	
				printf("Dequeued value is %d.\n",v);
			}
			else printf("Cannot dequeue as queue is empty.\n");
			print();
			
		}
	
		if(tempor==3){
			//IsFull
			int fl = isFull();
			if(fl==1)printf("\nThe queue is Full.\n\n");
			if(fl==0)printf("\nThe queue is not Full.\n\n");
		}
	
		if(tempor==4){
			//IsEmpty
			int fl2 = isEmpty();
			if(fl2==1)printf("\nThe queue is Empty.\n\n");
			if(fl2==0)printf("\nThe queue is not Empty.\n\n");
		}
			
		printf("-------------------------------------\n\n");
	}
}

void enqueue(int x){
	struct node *temp = malloc(sizeof(struct node));
	if(temp==NULL)printf("No memory.\n");
	else {
		if(fptr==NULL){
			temp->x = x;
			fptr = temp;
			rptr = temp;
			rptr->nptr = NULL;
		}
		else {
			temp->x = x;
			rptr->nptr = temp;
			rptr = temp;
			rptr->nptr = NULL;
		}
	}
}

int dequeue(){
	int t=0;
	t=fptr->x;
	if(fptr->nptr==NULL){
		fptr=NULL;
		rptr=NULL;
	}
	else {
		fptr=fptr->nptr;
	}
	return t;
}

int isFull(){
	if(malloc(sizeof(struct node))==NULL)return 1;
	else return 0;
}

int isEmpty(){
	if(fptr==NULL)return 1;
	else return 0;
}

void print(){
	if(fptr==NULL){
		printf("Queue is Empty.\n");
	}
	else {
		printf("\nElements of queue are,\n");
		struct node *tptr = fptr;
		int i=1;
		for(;tptr!=NULL;tptr=tptr->nptr){
			printf("Node %d: %d\n",i,tptr->x);
			i++;
		}
		printf("\n\n");
	}
}