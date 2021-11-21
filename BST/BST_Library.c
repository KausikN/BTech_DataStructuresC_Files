#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Tnode {
    struct Tnode *lcptr;
    int acc;
    char authorname[50];
    char title[50];
    struct Tnode *rcptr;
};

void insert(int a,char n[],char t[]);
void delete(char t[]);
void search(char t[]);
void print(struct Tnode *ptr);

struct Tnode *rptr=NULL;

void main(){
    printf("----------------------Library Management------------------------\n");
    
    int tempor = 1;
      while(tempor>0){
          printf("What do you want do?\nInsert		-	1\nDelete		-	2\nSearch 		-	3\nExit		-	0\nEnter Option: ");
        scanf("%d",&tempor);
        
        if(tempor==1){
              //Insert
              printf("-----------Insert------------\n");
            printf("Enter acc number: ");
            int val=0;
            scanf("%d",&val);
            printf("Enter author name: ");
            char val3[50];
            scanf("%s",val3);
            printf("Enter title: ");
            char val2[50];
            scanf("%s",val2);
            insert(val,val3,val2);
            print(rptr);
          }
          
          if(tempor==2){
            //Delete
            printf("------------Delete-------------\n");
            printf("Enter title to delete: ");
            char ti[50];
            scanf("%s",ti);
            delete(ti);
            print(rptr);
        }
    
        if(tempor==3){
            //Search
            printf("------------Search-------------\n");
            printf("Enter title to search: ");
            char ti2[50];
            scanf("%s",ti2);
            search(ti2);
            print(rptr);
        }
        
        printf("-------------------------------------\n\n");
    }
}

void insert(int a,char n[],char t[]){
    struct Tnode *temp = malloc(sizeof(struct Tnode));
    temp->acc=a;
    strcpy(temp->title,t);
    strcpy(temp->authorname,n);
    temp->lcptr=NULL;
       temp->rcptr=NULL;
      if(rptr==NULL){	
        rptr=temp;
    }
    else{
        struct Tnode *trptr=rptr;
        struct Tnode *pptr=NULL;
          while(trptr!=NULL){
            pptr=trptr;
            if(strcmp(trptr->title,t)>0){
                trptr=trptr->lcptr;	
            }
            else{
                trptr=trptr->rcptr;
            }
        }
        if(strcmp(pptr->title,t)>0){
            pptr->lcptr=temp;
        }
        else {
            pptr->rcptr=temp;
        }
    }	
}

void delete(char t[]){
    int b;
    char a[50];	
       struct Tnode *ptemp=NULL;
    struct Tnode *trptr=rptr;
    struct Tnode *pptr=NULL;	
    while(trptr!=NULL && strcmp(trptr->title,t)!=0){
        pptr=trptr;		
        if(strcmp(trptr->title,t)>0)
            trptr=trptr->lcptr;	
        else 
            trptr=trptr->rcptr;
    }
    if(trptr==NULL){
        printf("\nBook does not exist, so cant be deleted.\n\n");
    }
    else if(rptr->lcptr==NULL && rptr->rcptr==NULL){
        b=rptr->acc;
        strcpy(a,rptr->authorname);
        rptr=NULL;
    }
    else if(trptr->lcptr==NULL && trptr->rcptr==NULL){				//Leaf Node
        b=trptr->acc;
        strcpy(a,trptr->authorname);		
        if(strcmp(pptr->title,t)>0)
            pptr->lcptr=NULL;
        else
            pptr->rcptr=NULL;
    }
    else if(trptr->lcptr==NULL && trptr->rcptr!=NULL || trptr->lcptr!=NULL && trptr->rcptr==NULL){
        b=trptr->acc;
        strcpy(a,trptr->authorname);
        if(pptr==NULL){
            if(trptr->lcptr!=NULL){	
                rptr=trptr->lcptr;	
            }	
            else if(trptr->rcptr!=NULL){	
                rptr=trptr->rcptr;	
            }
        }
        else {
            if(strcmp(pptr->title,t)>0 && trptr->lcptr!=NULL){	
                pptr->lcptr=trptr->lcptr;	
            }	
            else if(strcmp(pptr->title,t)>0 && trptr->lcptr==NULL){	
                pptr->lcptr=trptr->rcptr;	
            }
            else if(strcmp(pptr->title,t)<=0 && trptr->rcptr!=NULL){	
                pptr->rcptr=trptr->lcptr;	
            }
            else {	
                pptr->rcptr=trptr->rcptr; 	  
            }
        }
    }
    else{
        struct Tnode *temp=trptr;
         ptemp=temp;		
        temp=temp->rcptr;
        while(temp->lcptr!=NULL){
            ptemp=temp;
            temp=temp->lcptr;
        }
        b=trptr->acc;
        trptr->acc=temp->acc;
        strcpy(a,trptr->authorname);
        strcpy(trptr->authorname,temp->authorname);		
       if(strcmp(ptemp->title,temp->title)>0)
               ptemp->lcptr=temp->rcptr;
       else
             ptemp->rcptr=temp->rcptr;
       }
    
}

void print(struct Tnode *ptr){
    printf("\n");
    if(rptr==NULL)printf("The Library is empty.\n");
    if(ptr!=NULL){
        print(ptr->lcptr);
        printf("---------------\n");
        printf("Acc: %d\n",ptr->acc);
        printf("Author name: %s\n",ptr->authorname);
        printf("Book title: %s\n",ptr->title);
        printf("---------------\n");
        print(ptr->rcptr);
    }
}

void search(char t[]){
    struct Tnode *trptr=rptr;
    struct Tnode *pptr=NULL;
    while(trptr!=NULL && strcmp(trptr->title,t)!=0){
        pptr=trptr;		
        if(strcmp(trptr->title,t)>0)
            trptr=trptr->lcptr;	
        else 
            trptr=trptr->rcptr;
    }
    if(trptr!=NULL){
        printf("Acc of %s: %d\n",trptr->title,trptr->acc);
        printf("Author name of %s: %s\n",trptr->title,trptr->authorname);
    }
    else {
        printf("Book not found.\n");
    }
}
