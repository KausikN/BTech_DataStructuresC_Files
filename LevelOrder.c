#include<stdio.h>
#include<stdlib.h>
struct Tnode
{
	int data;
	struct Tnode *lcptr;
	struct Tnode *rcptr;
};

//Prototypes
void insert(int x);
void Min(struct Tnode *ptr);
void Max(struct Tnode *ptr);
void LevelOrder(struct Tnode *ptr);
void Inorder(struct Tnode *ptr);
void delete(int x);
void Level(struct Tnode *ptr,int level);
int height(struct Tnode *ptr);


struct Tnode *rptr=NULL;

void main(){
	printf("----------------------Min, Max and Level Order------------------------\n");
	
	int tempor = 1;
  	while(tempor>0){
  		printf("What do you want do?\nInsert			-	1\nDelete			-	2\nMinimum 		-	3\nMaximum 		-	4\nLevel Order 	-	5\nPrint 		-	6\nExit		-	0\nEnter Option: ");
		scanf("%d",&tempor);
		
		if(tempor==1){
  			//Insert
  			printf("-----------Insert------------\n");
			printf("Enter value: ");
			int x;
			scanf("%d",&x);
			insert(x);
  		}
  		
  		if(tempor==2){
			//Delete
			printf("------------Delete-------------\n");
			printf("Enter value to delete: ");
			int a;
			scanf("%d",&a);
			delete(a);
		}
	
		if(tempor==3){
			//Minimum
			if(rptr==NULL)printf("\n\nNo minimum as BST is Empty.\n\n");
			else Min(rptr);
		}
		
		if(tempor==4){
			//Maximum
			if(rptr==NULL)printf("\n\nNo maximum as BST is Empty.\n\n");
			else Max(rptr);
		}
		
		if(tempor==5){
			//LevelOrder
			if(rptr==NULL)printf("\n\nBST is Empty.\n\n");
			else {
				LevelOrder(rptr);
				printf("\n\n");
			}
		}
		
		if(tempor==6){
			//Inorder
			if(rptr==NULL)printf("\n\nBST is Empty.\n\n");
			else {
				Inorder(rptr);
				printf("\n\n");
			}
		}
		
		printf("-------------------------------------\n\n");
	}
}

void insert(int x){
   	struct Tnode *tmp=malloc(sizeof(struct Tnode));
	tmp->data=x;
	tmp->lcptr=NULL;
   	tmp->rcptr=NULL;
   	if(rptr==NULL){	
		rptr=tmp;
	}
	else{
		struct Tnode *ptr=rptr;
		struct Tnode *pptr=NULL;
    	while(ptr!=NULL){
			pptr=ptr;
         	if(x<ptr->data){
				ptr=ptr->lcptr;	
			}
			else{
				ptr=ptr->rcptr;
			}
		}
		if(x<pptr->data)
			pptr->lcptr=tmp;
		else
			pptr->rcptr=tmp;	
	}	

}

void Inorder(struct Tnode *ptr){
	if(ptr!=NULL){
		Inorder(ptr->lcptr);
		printf("%d ",ptr->data);
		Inorder(ptr->rcptr);
	}
}

void LevelOrder(struct Tnode *ptr){
	if(ptr!=NULL){
		int h=height(ptr);
		for(int i=1;i<=h;i++)Level(ptr,i);
	}
}

void Level(struct Tnode *ptr,int level){
	if(ptr!=NULL){
		if(level==1)printf("%d ",ptr->data);
		else if(level>1){
			Level(ptr->lcptr,level-1);
			Level(ptr->rcptr,level-1);
		}
	}
}

int height(struct Tnode *ptr){
	if(ptr==NULL)return 0;
	else  {
		int lh=height(ptr->lcptr);
		int rh=height(ptr->rcptr);
		if(lh>rh)return (lh+1);
		else return (rh+1);
	}
}

void Min(struct Tnode *ptr){
	while(ptr->lcptr!=NULL)ptr=ptr->lcptr;
	printf("\n\nThe minimum element is %d.\n\n",ptr->data);
}

void Max(struct Tnode *ptr){
	while(ptr->rcptr!=NULL)ptr=ptr->rcptr;
	printf("\n\nThe maximum element is %d.\n\n",ptr->data);
}

void delete(int x){	
   	struct Tnode *ptmp=NULL;
	struct Tnode *ptr=rptr;
	struct Tnode *pptr=NULL;	
	while(ptr!=NULL && ptr->data!=x){
		pptr=ptr;		
		if(x>=ptr->data)
			ptr=ptr->rcptr;	
		else 
			ptr=ptr->lcptr;
	}	
	if(ptr==NULL){
		printf("\n Deletion Fails\n");
	}
	else if(rptr->lcptr==NULL && rptr->rcptr==NULL){		
		rptr=NULL;	
	}
	else if(ptr->lcptr==NULL && ptr->rcptr==NULL){		
		if(x<pptr->data)
			pptr->lcptr=NULL;
		else
			pptr->rcptr=NULL;
	}
	else if(ptr->lcptr==NULL && ptr->rcptr!=NULL || ptr->lcptr!=NULL && ptr->rcptr==NULL){		
		if(x<pptr->data && ptr->lcptr!=NULL)
			pptr->lcptr=ptr->lcptr;		
		else if(x<pptr->data && ptr->lcptr==NULL)
			pptr->lcptr=ptr->rcptr;
		else if(x>=pptr->data && ptr->lcptr!=NULL)
			pptr->rcptr=ptr->lcptr;
		else
			pptr->rcptr=ptr->rcptr;   
	}
	else{		
		struct Tnode *tmp=ptr;
   	  	ptmp=tmp;		
		tmp=tmp->rcptr;
		while(tmp->lcptr!=NULL){
       		ptmp=tmp;
			tmp=tmp->lcptr;
		}		
		ptr->data=tmp->data;	 
       	if(tmp->data < ptmp->data)
         	ptmp->lcptr=tmp->rcptr;
       	else
       		ptmp->rcptr=tmp->rcptr;

	}
}
