#include<stdio.h>
#include<stdlib.h>
struct Tnode
{
    int data;
    struct Tnode *lcptr;
    struct Tnode *rcptr;
};
struct Tnode *rptr=NULL;
void insert(int x)
{
   struct Tnode *tmp=malloc(sizeof(struct Tnode));
    tmp->data=x;
    tmp->lcptr=NULL;
   tmp->rcptr=NULL;
   if(rptr==NULL)
    {	
        rptr=tmp;
    }
    else
    {
        struct Tnode *ptr=rptr;
        struct Tnode *pptr=NULL;
      while(ptr!=NULL)
        {
            pptr=ptr;
         if(x<ptr->data)
            {
                ptr=ptr->lcptr;	
            }
            else
            {
                ptr=ptr->rcptr;
            }
        }
        if(x<pptr->data)
            pptr->lcptr=tmp;
        else
            pptr->rcptr=tmp;	
    }	

}
void Inorder(struct Tnode *ptr)
{
    if(ptr!=NULL)
    {
        Inorder(ptr->lcptr);
        printf("%d ",ptr->data);
        Inorder(ptr->rcptr);
    }
}
int delete(int x)
{
    int b=-666;	
   struct Tnode *ptmp=NULL;
    struct Tnode *ptr=rptr;
    struct Tnode *pptr=NULL;	
    while(ptr!=NULL && ptr->data!=x)
    {
        pptr=ptr;		
        if(x>=ptr->data)
            ptr=ptr->rcptr;	
        else 
            ptr=ptr->lcptr;
    }	
    if(ptr==NULL)
    {
        printf("\n Deletion Fails");
    }
    else if(rptr->lcptr==NULL && rptr->rcptr==NULL)
    {
        b=rptr->data;		
        rptr=NULL;	
    }
    else if(ptr->lcptr==NULL && ptr->rcptr==NULL) //Case 1:Delete Leaf Node
    {
        b=ptr->data;		
        if(x<pptr->data)
            pptr->lcptr=NULL;
        else
            pptr->rcptr=NULL;
    }
    else if(ptr->lcptr==NULL && ptr->rcptr!=NULL || ptr->lcptr!=NULL && ptr->rcptr==NULL)
    {
        b=ptr->data;		
        if(x<pptr->data && ptr->lcptr!=NULL)
            pptr->lcptr=ptr->lcptr;		
        else if(x<pptr->data && ptr->lcptr==NULL)
            pptr->lcptr=ptr->rcptr;
        else if(x>=pptr->data && ptr->lcptr!=NULL)
            pptr->rcptr=ptr->lcptr;
        else
            pptr->rcptr=ptr->rcptr;   
    }
    else
    {		
        struct Tnode *tmp=ptr;
      ptmp=tmp;		
        tmp=tmp->rcptr;
      
        while(tmp->lcptr!=NULL)
        {
         ptmp=tmp;
            tmp=tmp->lcptr;
        }
        b=ptr->data;		
        ptr->data=tmp->data;	
            

        //To delete suc node pointed to by tmp, and its parent is ptmp
      
       if(tmp->data < ptmp->data)
         ptmp->lcptr=tmp->rcptr;
       else
        ptmp->rcptr=tmp->rcptr;

    }
    return b;
}
void main()
{
   
    insert(5);
    insert(3);
    insert(10);
    insert(20);
    insert(95);
    insert(8);
   insert(20);
    insert(45);
   insert(100);

    Inorder(rptr);
   delete(95);
   printf("\n");
   Inorder(rptr);
}
