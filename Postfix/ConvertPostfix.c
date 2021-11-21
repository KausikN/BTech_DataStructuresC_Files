#include<stdio.h>

//Structs
struct ElemStack{
    int top;
    char n[200];
};

struct OpStack{
    int top;
    int n[200];
};
//Prototypes
void push(struct ElemStack *pl, int x);
int pop(struct ElemStack *pl);
void Evaluate(struct ElemStack *pl, char e[], int s);
void Convert(struct OpStack *pl, char e[], int s);

void main(){
    printf("------------------------PostfixConversion-------------------------\n");
    int t = 0;
    struct OpStack p;
    char exp[200];
    int len=0;
    while(t==0){
        p.top=-1;
        printf("Enter the expression: ");
        scanf("%s",exp);
        printf("\nEntered Expression: %s%n\n",exp,&len);    
        len = len -21;
        Convert(&p,exp,len);
        printf("Do you want to exit (0 for no 1 for yes): ");
        scanf("%d",&t);
        printf("-------------------------------------------------------\n");
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
            int n1 = pop(pl);
            int n2 = pop(pl);
            int nt = n1+n2;
            if(n1!=-967 && n2!=-967){
                push(pl,nt);
            }
            else i=s+1;
        }
        else if(e[i]=='-'){
            int n1 = pop(pl);
            int n2 = pop(pl);
            int nt = n2-n1;
            if(n1!=-967 && n2!=-967){
                push(pl,nt);
            }
            else i=s+1;
        }
        else if(e[i]=='*'){
            int n1 = pop(pl);
            int n2 = pop(pl);
            int nt = n1*n2;
            if(n1!=-967 && n2!=-967){
                push(pl,nt);
            }
            else i=s+1;
        }
        else if(e[i]=='/'){
            int n1 = pop(pl);
            int n2 = pop(pl);
            int nt = n2/n1;
            if(n1!=-967 && n2!=-967){
                push(pl,nt);
            }
            else i=s+1;
        }
    }
    printf("\nThe answer is: %d\n",pl->n[0]);
}


void Convert(struct OpStack *pl, char e[], int s){
    char ce[200];
    int index=0;
    int pre =0;
    int bracketcheck=0;
    for(int i=0;i<s;i++){
        if(e[i]>47 && e[i]<58){
            ce[index] = e[i];
            index++;
        }
        else if(e[i]=='+' || e[i]=='-'){
            if(bracketcheck==0){
                while(pl->top>-1){
                    ce[index]=pop(pl);
                    index++;
                }
            }
            else {
                while(pl->n[pl->top]!='('){
                    ce[index]=pop(pl);
                    index++;
                }
            }
            pre=0;
            push(pl,e[i]);    
        }
        else if(e[i]=='*' || e[i]=='/'){
            if(bracketcheck==0){
                while(pre!=0){
                    if(pl->n[pl->top] == '+'|| pl->n[pl->top]=='-')pre=0;
                    else {
                        ce[index]=pop(pl);
                        index++;
                    }
                }
            }
            else{
                while(pre!=0 || pl->n[pl->top]!='('){
                    if(pl->n[pl->top] == '+'|| pl->n[pl->top]=='-')pre=0;
                    else {
                        ce[index]=pop(pl);
                        index++;
                    }
                }
            }
            pre=1;
            push(pl,e[i]);
        }
        else if(e[i]=='('){
            push(pl,e[i]);
            bracketcheck++;
        }
        else if(e[i]==')'){
            if(bracketcheck ==1){
                    while(pl->n[pl->top]!='('){
                        ce[index]=pop(pl);
                        index++;
                    }
                    int notused = pop(pl);
                    bracketcheck--;
            }
            else {
                printf("\nEntered expression is invalid.\n");
                break;
            }
        }
    }
    while(pl->top>-1){
        ce[index]=pop(pl);
        index++;
    }
    printf("\nThe Converted expression: %s\n",ce);
    struct ElemStack l;
    l.top=-1;
    Evaluate(&l,ce,s);
}