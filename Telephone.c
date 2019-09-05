#include<stdio.h>
#include<stdlib.h>
struct Tnode
{
	long int aadhar;
	long int tel;
	int height;
	struct Tnode *lcptr;
	struct Tnode *rcptr;
};

//Prototypes
struct Tnode * insert(struct Tnode *ptr,int x);
int findheight(struct Tnode *ptr);
void heightUpdate(struct Tnode *ptr);
struct Tnode * RotateRight(struct Tnode *ptr);
struct Tnode * RotateLeft(struct Tnode *ptr);
struct Tnode * RotateLeftRight(struct Tnode *ptr);
struct Tnode * RotateRightLeft(struct Tnode *ptr);
void Search(int x);
void Inorder(struct Tnode *ptr);
//int BF(struct Tnode *ptr);

struct Tnode *rptr=NULL;
int tele;

void main(){
	printf("----------------------Telephone Directory------------------------\n");
	
	int tempor = 1;
  	while(tempor>0){
  		printf("What do you want do?\nInsert			-	1\nSearch			-	2\nPrint 		-	6\nExit		-	0\nEnter Option: ");
		scanf("%d",&tempor);
		
		if(tempor==1){
  			//Insert
  			printf("-----------Insert------------\n");
			printf("Enter Aadhar number: ");
			long int x;
			scanf("%ld",&x);
			printf("Enter Telephone number: ");
			long int x2;
			scanf("%ld",&x2);
			tele=x2;
			insert(rptr,x);
			Inorder(rptr);
  		}
  		
  		if(tempor==2){
			//Search
			printf("------------Search-------------\n");
			printf("Enter Aadhar number to search: ");
			long int a;
			scanf("%ld",&a);
			Search(a);
			Inorder(rptr);
		}
		
		if(tempor==6){
			//Inorder
			if(rptr==NULL)printf("\n\nDirectory is Empty.\n\n");
			else {
				Inorder(rptr);
				printf("\n\n");
			}
		}
		
		printf("-------------------------------------\n\n");
	}
}

struct Tnode * insert(struct Tnode *ptr,int x){
	if(ptr==NULL){
		ptr = malloc(sizeof(struct Tnode));
		ptr->aadhar=x;
		ptr->tel=tele;
		ptr->lcptr=NULL;
		ptr->rcptr=NULL;
		ptr->height=0;
		if(rptr==NULL)rptr=ptr;
	}
	else {
		if(x<ptr->aadhar){
			ptr->lcptr=insert(ptr->lcptr,x);
			if(findheight(ptr->lcptr)-findheight(ptr->rcptr)==2 || findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2){
				if(x<(ptr->lcptr)->aadhar)ptr=RotateRight(ptr);
				else ptr=RotateLeftRight(ptr);
			}
		}
		else {
			ptr->rcptr=insert(ptr->rcptr,x);
			if(findheight(ptr->lcptr)-findheight(ptr->rcptr)==2 || findheight(ptr->lcptr)-findheight(ptr->rcptr)==-2){
				if(x>(ptr->rcptr)->aadhar)ptr=RotateLeft(ptr);
				else ptr=RotateRightLeft(ptr);
			}
		}
	}
	heightUpdate(ptr);
	return ptr;
}

int findheight(struct Tnode *ptr){
	int h1,h2;
	if(ptr==NULL)return -1;
	else {
		h1=findheight(ptr->lcptr);
		h2=findheight(ptr->rcptr);
		if(h1>h2)return (h1+1);
		else return (h2+1);
	}
}

void heightUpdate(struct Tnode *ptr){
	int h1,h2;
	if(ptr->lcptr==NULL)h1=-1;
	else h1=(ptr->lcptr)->height;
	if(ptr->rcptr==NULL)h2=-1;
	else h2=(ptr->rcptr)->height;
	if(h1<h2)ptr->height=h2+1;
	else ptr->height=h1+1;
}
/*
int BF(struct Tnode *ptr){
	int bf,h1,h2;
	if(ptr==NULL)return 0;
	else{
		if(ptr->lcptr==NULL)h1=-1;
		else h1=(ptr->lcptr)->height;
		if(ptr->rcptr==NULL)h2=-1;
		else h2=(ptr->rcptr)->height;
		bf = h1-h2;
	}
	return bf;
}
*/
struct Tnode * RotateRight(struct Tnode *ptr){
	struct Tnode *jptr = ptr;
	struct Tnode *kptr = ptr->lcptr;
	jptr->lcptr=kptr->rcptr;
	kptr->rcptr=jptr;
	heightUpdate(jptr);
	heightUpdate(kptr);
	return kptr;
}

struct Tnode * RotateLeft(struct Tnode *ptr){
	struct Tnode *jptr = ptr;
	struct Tnode *kptr = ptr->rcptr;
	jptr->rcptr=kptr->lcptr;
	kptr->lcptr=jptr;
	heightUpdate(jptr);
	heightUpdate(kptr);
	return kptr;
}

struct Tnode * RotateLeftRight(struct Tnode *ptr){
	struct Tnode *jptr = ptr;
	struct Tnode *kptr = ptr->lcptr;
	ptr->lcptr=RotateLeft(kptr);
	return(RotateRight(jptr));
}

struct Tnode * RotateRightLeft(struct Tnode *ptr){
	struct Tnode *jptr = ptr;
	struct Tnode *kptr = ptr->rcptr;
	ptr->lcptr=RotateRight(kptr);
	return(RotateLeft(jptr));
}

void Inorder(struct Tnode *ptr){
	if(ptr!=NULL){
		Inorder(ptr->lcptr);
		//int b= BF(ptr);
		printf("Aadhar: %ld and Telephone: %ld of Height: %d with BF: %d\n",ptr->aadhar,ptr->tel,ptr->height,findheight(ptr->lcptr)-findheight(ptr->rcptr));
		Inorder(ptr->rcptr);
	}
}

void Search(int x){
	int check=0;
	if(rptr==NULL){
		printf("Directory is empty.\n");
	}
	else {
		struct Tnode *ptr=rptr;
		while(ptr!=NULL){
			if(ptr->aadhar==x){
				printf("The Aadhar number %ld has Telephone number %ld.\n",ptr->aadhar,ptr->tel);
				check=1;
				break;
			}
			else if (x>ptr->aadhar){
				ptr=ptr->rcptr;
			}
			else ptr=ptr->lcptr;
		}
	}
	if(check==0)printf("%d does not exist.\n",x);
}


