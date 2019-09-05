#include<stdio.h>
#include<stdlib.h>

//Structs
struct node{
	int x;
	struct node *nptr;
};

//Prototypes
void push(int x);
int pop();

struct node *top = NULL;

void main(){
	printf("------------------Factorial using Stack--------------------\n");	
	printf("Enter n: ");
	int n;
	scanf("%d",&n);
	push(1);
	for(int i=2;i<n+1;i++){
		int i2 = pop();
		i2 = (int)i*i2;
		push(i2);
	}
	int ans = pop();
	printf("n! : %d",ans);
	printf("\n-------------------------------------\n\n");
}

//Functions
void push(int x){
	struct node *temp = malloc(sizeof(struct node));
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

int pop(){
	int t=top->x;
	if(top->nptr==NULL){
		top=NULL;
	}
	else {
		top=top->nptr;
	}
	return t;
}
