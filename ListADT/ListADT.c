#include<stdio.h>

//Struct
struct List{
    int a[10];
    int lsize;
};

//Fuction Prototypes
void insert(struct List *pl,int pos,int x);
int delete(struct List *pl,int pos);
int search(struct List l,int x);
void print(struct List l);
int isFull(struct List l);
int isEmpty(struct List l);

//Main Function
void main(){
    printf("-------------------------List ADT-------------------------\n\n");
    struct List l;
    l.lsize = 0;
    printf("Enter number of inputs (less than 11): ");
    scanf("%d",&l.lsize);
    printf("Enter %d inputs: ",l.lsize);
    
    //Give Values to array
    for(int i=0;i<l.lsize;i++){
        scanf("%d",&l.a[i]);
    }
    
    print(l);
    
    int tempor=1;
    
    while(tempor>0){
    
    printf("What do you want do?\nInsert		-	1\nDelete		-	2\nSearch		-	3\nCheck if Full	-	4\nCheck if Empty	-	5\nExit		-	0\nEnter Option: ");
    scanf("%d",&tempor);
    
    if(tempor==1){
    //Insert
    int v1,p1;
    printf("-------Insert--------\n");
    printf("Enter value and position to insert: ");
    scanf("%d %d",&v1,&p1);
    insert(&l,p1,v1);
    print(l);
    }
    
    if(tempor==2){
    //Delete
    int p2,t;
    t = l.lsize;
    printf("-------Delete--------\n");
    printf("Enter position to delete: ");
    scanf("%d",&p2);
    int v2 = delete(&l,p2);
    print(l);
    if(t>l.lsize)printf("Deleted value was: %d\n",v2);
    }
    
    if(tempor==3){
    //Search
    int sv,sp;
    printf("Enter value to search: ");
    scanf("%d",&sv);
    sp = search(l,sv);
    if(sp<0)printf("Entered value is not there in the array.\n");
    else printf("Entered value %d can be found at index %d.\n",sv,sp);
    }
    
    if(tempor==4){
    //IsFull
    int fl = isFull(l);
    if(fl==1)printf("The array is Full.\n");
    if(fl==0)printf("The array is not Full.\n");
    }
    
    if(tempor==5){
    //IsEmpty
    int fl2 = isEmpty(l);
    if(fl2==1)printf("The array is Empty.\n\n");
    if(fl2==0)printf("The array is not Empty.\n\n");
    }
    }
    
}

void insert(struct List *pl,int pos,int x){
    int i;
    
    //Boundary Conditions
    if(pl->lsize==10)
    printf("\nERROR: Array is Full.\n");
    
    else if(pos>pl->lsize || pos<0 || pos>9 )
    printf("\nERROR: Entered position cannot be inserted (index position should be between 0 and 9 only).\n");
    
    else{
    //insertion
    for(i=pl->lsize;i>pos;i--){
        pl->a[i] = pl->a[i-1];
    }
    pl->a[pos] = x;
    (pl->lsize)++;
    }
}

void print(struct List l){
    int i;
    printf("\nValues in the array are: ");
    for(i=0;i<l.lsize;i++){
        printf("%d ",l.a[i]);
    }
    printf("\n\n");
}
int delete(struct List *pl,int pos){
    int i,temp=0;
    
    //Boundary Conditions
    if(pl->lsize<=0)
    printf("\nERROR: Array has no elements to delete.\n");
    
    else if(pos<0 || pos>(pl->lsize)-1 || pos>9)
    printf("\nERROR: Entered position cannot be deleted (index position should be between 0 and 9 only).\n");
            
    else{
    temp = pl->a[pos];
    for(i=pos;i<(pl->lsize)-1;i++){
        pl->a[i] = pl->a[i+1];
    }
    (pl->lsize)--;
    }
    return (temp);
}

int search(struct List l,int x){
    int i,r=-1;
    for(i=0;i<l.lsize;i++){
        if(l.a[i]==x){
            r=i;
            break;
        }
    }
    return (r);
}

int isFull(struct List l){
    if(l.lsize==10)return 1;
    else return 0;
}

int isEmpty(struct List l){
    if(l.lsize==0)return 1;
    else return 0;
}