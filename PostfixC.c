#include<stdio.h>

//Structs
struct ElemStack{
	int top;
	int n[200];
};

//Prototypes
void push(struct ElemStack *pl, int x);
int pop(struct ElemStack *pl);
void Evaluate(struct ElemStack *pl, char e[], int s);

void main(){
	printf("------------------------Library-------------------------\n");
	int t = 0;
	struct ElemStack l;
	char exp[200];
	int len=0;
	while(t==0){
		printf("Enter the postfix expression: ");
		scanf("%s",exp);
		printf("\nEntered Expression: %s%n\n",exp,&len);	///////MAYBE ERROR
		len = len -21;
		Evaluate(&l,exp,len);
		printf("Do you want to exit (0 for no 1 for yes): ");
		scanf("%d",&t);
	}
}

//Functions
void push(struct ElemStack *pl, int x){
	if(pl->top == 199)printf("\nGiven expression is too large.\n");
	else {
		pl->top++;
		pl->n[pl->top] = x;
	}
}

int pop(struct ElemStack *pl){
	int popVal=-967;//ERROR CODE
	if(pl->top == -1)printf("\nPlease enter a valid postfix expression.\n");
	else {
		popVal = pl->n[pl->top];
		pl->top--;
	}
	return popVal;
}

void Evaluate(struct ElemStack *pl, char e[], int s){
	for(int i=0;i<s;i++){
		if(e[i]>47 && e[i]<58){
			int temp = e[i];
			temp = temp - 48;
			push(pl,temp);
		}
		else if(e[i]=='+'){
			int n1 = pop(pl);printf("\n\nHII\n\n");
			int n2 = pop(pl);
			int nt = n1+n2;
			if(n1!=-967 && n2!=-967){
				push(pl,nt);
				i=s+1;
			}
		}
		else if(e[i]=='-'){
			int n1 = pop(pl);
			int n2 = pop(pl);
			int nt = n1-n2;
			if(n1!=-967 && n2!=-967){
				push(pl,nt);
				i=s+1;
			}
		}
		else if(e[i]=='*'){
			int n1 = pop(pl);
			int n2 = pop(pl);
			int nt = n1*n2;
			if(n1!=-967 && n2!=-967){
				push(pl,nt);
				i=s+1;
			}
		}
		else if(e[i]=='/'){
			int n1 = pop(pl);
			int n2 = pop(pl);
			int nt = n1/n2;
			if(n1!=-967 && n2!=-967){
				push(pl,nt);
				i=s+1;
			}
		}
	}
	if(pl->top != 0)printf("\nEntered expression is invalid.\n");
	else printf("\nThe answer is: %d\n",pl->n[0]);
}
