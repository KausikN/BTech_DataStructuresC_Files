#include<stdio.h>

//Structs
struct Book{
	int accountnumber;
	char author[25];
	char booktitle[25];
};

struct Library{
	int top;
	struct Book bl[100];
};

//Prototypes
void push(struct Library *pl, struct Book bt);
void pop(struct Library *pl);
int search(struct Library *pl,int acc);
int isfull(struct Library l);
int isempty(struct Library l);
void print(struct Library l);

void main(){
	printf("------------------------Library-------------------------\n");
	int t = 0;
	struct Library l;
	l.top = -1;
	struct Book b;
	while(t==0){
		printf("What do you want to do?\nSearch - Type 1\nAdd - Type 2\nDelete - Type 3\nCheck if Library is full - Type 4\nCheck if Library is empty - Type 5\nEnter your choice: ");
		int choice = 1;
		scanf("%d",&choice);
		if(choice == 1){
			if(l.top==-1)printf("The Library has no books currently.\n");
			else {
				int acc;
				printf("Enter the Account number you want to search: ");
				scanf("%d",&acc);
				int res = search(&l,acc);
				if(res == -1)printf("A Book with the given account number does not exist in the Library.\n");
				else printf("A Book with the given account number %d\nBook Title: %s\nAuthor: %s\n",l.bl[res].accountnumber,l.bl[res].booktitle,l.bl[res].author);
			}
		}
		else if(choice == 2){
			printf("Please enter the account number: ");
			scanf("%d",&b.accountnumber);
			printf("Please enter the Author name: ");
			scanf("%s",b.author);
			printf("Please enter the Book title: ");
			scanf("%s",b.booktitle);
			push(&l,b);
			print(l);
		}
		else if(choice == 3){
			pop(&l);
			print(l);
		}
		else if(choice == 4){
			int resp = isfull(l);
			if(resp == 1)printf("Library is full.\n");
			else if(resp == 0)printf("Library is not full.\n");
		}
		else if(choice == 5){
			int resp = isempty(l);
			if(resp == 1)printf("Library is empty.\n");
			else if(resp == 0)printf("Library is not empty.\n");
		}
		else printf("Please enter a valid choice.\n");
		printf("Do you want to exit? (Enter 0 for no and 1 for yes): ");
		scanf("%d",&t);
		printf("-------------------------------------------------\n");
	}
}

//Functions
void push(struct Library *pl, struct Book bt){
	if(pl->top == 99)printf("Library is already full. No more books can be added.\n");
	else {
		pl->top++;
		pl->bl[pl->top] = bt;
	}
}

void pop(struct Library *pl){
	if(pl->top == -1)printf("Cannot delete as Library is already empty.\n");
	else {
		pl->top--;
		printf("The top book has been deleted.\n");
	}
}

void print(struct Library l){
	for(int i=0;i<l.top+1;i++){
		printf("Book -     Acc No. : %d\n",l.bl[i].accountnumber);
		printf("	   Author  : %s\n",l.bl[i].author);
		printf("	   Title   : %s\n",l.bl[i].booktitle);
	}
}

int search(struct Library *pl,int ac){
	int occurence = -1;
	for(int i=0;i < pl->top+1;i++){
		if(pl->bl[i].accountnumber == ac){
			occurence = i;
			break;
		}
	}
	return occurence;
}

int isfull(struct Library l){
	if(l.top == 99)return 1;
	else return 0;
}

int isempty(struct Library l){
	if(l.top == -1)return 1;
	else return 0;
}

