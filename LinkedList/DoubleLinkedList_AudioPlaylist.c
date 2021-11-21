#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structs
struct node
{
    struct node *pptr;
    char name[30];
    struct node *nptr;
};

//Prototypes
void Insert();
void Delete(char c[]);
int Search(char a[],int chk);
void print();
void Play(char b[]);
void next();
void prev();

//Start
char n[30];
struct node *hptr = NULL;
struct node *rear = NULL;
struct node *playing = NULL;
int no=0;

void main(){
    printf("----------------------Audio Playlist (Double Linked List)-----------------------\n");
    int tempor=1;
    while(tempor>0){
        printf("What do you want do?\nInsert Audio File	-	1\nDelete Audio File	-	2\nPlay File		-	3\nNext Audio		-	4\nPrevious Audio		-	5\nExit			-	0\nEnter Option: ");
        scanf("%d",&tempor);
        
        if(tempor==1){
            //Insert
            printf("-------Insert New Audio--------\n");
            printf("Enter name of song: ");
            scanf("%s",n);
            Insert();
            print();
        }
        
        if(tempor==2){
            //Delete
            printf("-------Delete Audio--------\n");
            char c[30];
            printf("Enter name of song: ");
            scanf("%s",c);
            Delete(c);
            print();
        }
    
        if(tempor==3){
            //Play
            char c[30];
            printf("-------Play File--------\n");
            printf("Enter name of file: ");
            scanf("%s",c);
            Play(c);
            print();
        }
    
        if(tempor==4){
            //Next
            if(playing->nptr != NULL){
                playing = playing->nptr;
            }
            else printf("\nThis is the last song.\n");
            printf("\n\nCurrently playing %s.\n\n",playing->name);
            print();
        }
        
        if(tempor==5){
            //Prev
            if(playing->pptr != NULL){
                playing = playing->pptr;
            }
            else printf("\nThis is the first song.\n");
            printf("\n\nCurrently playing %s.\n\n",playing->name);
            print();
        }
            
        printf("-------------------------------------\n\n");
    }
}

void Insert(){
    struct node *temp = malloc(sizeof(struct node));
    if(temp==NULL)printf("No memory.\n");
    else {
        if(hptr==NULL){
            strcpy(temp->name,n);
            rear = temp;
            hptr = temp;
            temp->nptr = NULL;
            temp->pptr = NULL;
        }
        else {
            strcpy(temp->name,n);
            temp->pptr = rear;
            rear->nptr = temp;
            rear = temp;
            temp->nptr = NULL;
        }
        no++;
    }
}

void Delete(char c[]){
    if(hptr==NULL)printf("Playlist already empty.\n");
    else {
        int pos = Search(c,0);
        if(pos==-1)printf("Cannot delete as song not found.\n");
        else {
            struct node *thptr = hptr;
            for(int i=0;i<pos-1;i++){
                thptr = thptr->nptr;
            }
            if(pos == no-1){
                thptr->nptr=NULL;
                rear=thptr;
            }
            else{
                if(pos==0){
                    hptr=hptr->nptr;
                    hptr->pptr = NULL;
                }
                else{
                    ((thptr->nptr)->nptr)->pptr = thptr;
                    thptr->nptr = (thptr->nptr)->nptr;
                }
            }
            no--;
            if(no==0)hptr=NULL;
            printf("Deleted %s.\n",c);
        }
    }
}

void print(){
    if(hptr==NULL)printf("Playlist is empty.\n");
    else {
        struct node *tmp = hptr;
        int i=1;
        while(tmp!=NULL){
            printf("%d. %s.mp3\n",i,tmp->name);
            i++;
            tmp=tmp->nptr;
        }
    }
}

int Search(char a[],int chk){
    int p =-1;
    struct node *t=hptr;
    int i=0;
    if(strcmp(a,t->name)==0){
        p=0;
    }
    else {
        while(strcmp(a,t->name)!=0 && t->nptr!=NULL){
            i++;
            t = t->nptr;
        }
        if(i<no-1)p=i;
    }
    if(chk==1)playing = t;
    return p;
}

void Play(char b[]){
    int pos = Search(b,1);
    if(pos==-1)printf("Song to be played not found.\n");
    else {
        printf("\n\nCurrently Playing %s.\n\n",b);
    }
}