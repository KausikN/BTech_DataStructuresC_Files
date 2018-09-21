#include<stdio.h>

//Structs
struct Passenger
{
  	int pnr;
 	char name[25];
  	int fare;
};

struct waitingListQueue
{
  	struct Passenger pa[100];
  	int rear;
  	int front;
};

struct confirmedListQueue
{
  	struct Passenger pa[100];
  	int rear;
  	int front;
};

//Prototypes
int search(struct confirmedListQueue c,int pt);
void enqueueConfirmed(struct confirmedListQueue *pc,struct Passenger p);
void enqueue(struct waitingListQueue *pw,struct Passenger p);
int dequeue(struct waitingListQueue *pw);
void print(struct waitingListQueue w,struct confirmedListQueue c);
int isFull(struct waitingListQueue w);
int isEmpty(struct waitingListQueue w);

//Main function
void main(){
	//initialise
	struct Passenger p;
  	struct waitingListQueue w;
  	struct confirmedListQueue c;
  	int PNRLast = 0;
  	w.front = -1;
  	w.rear = -1;
  	c.front = -1;
  	c.rear = -1;
  	//Code
  	printf("--------------------------Waiting List----------------------------\n");
  	int tempor = 1;
  	while(tempor>0){
  		printf("What do you want do?\nAdd a passenger		-	1\nConfirm a seat		-	2\nCheck if Full		-	3\nCheck if Empty		-	4\nCheck PNR in Confirmed List -   5\nExit			-	0\nEnter Option: ");
		scanf("%d",&tempor);
		
		if(tempor==1){
  			//Enqueue
  			printf("-------Add Passenger--------\n");
			printf("Enter Name of Passenger: ");
			scanf("%s",p.name);
			printf("Enter fare: ");
			scanf("%d",&p.fare);
			PNRLast++;
			p.pnr = PNRLast;
			enqueue(&w,p);
			print(w,c);
  		}
  		
  		if(tempor==2){
			//Dequeue
			//Storing to be dequeued person details and sending to confirmed list
			enqueueConfirmed(&c,w.pa[w.front]);
			if(c.rear<99){
				int v = dequeue(&w);
				if(v<0)printf("There are no passengers in the waiting list to confirm seat.\n");
				else {
					printf("Seat confirmed for %s.\n",c.pa[c.front].name);
				}
			}
			print(w,c);
			
		}
	
		if(tempor==3){
			//IsFull
			int fl = isFull(w);
			if(fl==1)printf("\nThe Waiting list is Full.\n\n");
			if(fl==0)printf("\nThe Waiting list is not Full.\n\n");
		}
	
		if(tempor==4){
			//IsEmpty
			int fl2 = isEmpty(w);
			if(fl2==1)printf("\nThe Waiting list is Empty.\n\n");
			if(fl2==0)printf("\nThe Waiting list is not Empty.\n\n");
		}
		
		if(tempor==5){
			//Confirmed List search
			int pinp = 0;
			printf("Enter a PNR to search: ");
			scanf("%d",&pinp);
			
			int fl2 = search(c,pinp);
			if(fl2 == -1){
				printf("Given PNR %d is NOT found in the confirmed list.\n",pinp);
			}
			else if(fl2 > -1){
				printf("Given PNR %d exists in the confirmed list and their details are,\nName: %s\nFare: %d\n",pinp,c.pa[fl2].name,c.pa[fl2].fare);
			}
		}
		
		printf("-------------------------------------\n\n");
	}
  	
}

void enqueue(struct waitingListQueue *pw,struct Passenger p){
	//Boundary Conditions
	if(pw->rear == 99)printf("the waiting list is already full.\n");
	//Empty Condition
	if(pw->front == -1 && pw->rear == -1){
		pw->front++;
		pw->rear++;
	}
	else {
		pw->rear++;
	}
	pw->pa[pw->rear] = p;
}

void enqueueConfirmed(struct confirmedListQueue *pc,struct Passenger p){
	//Boundary Conditions
	if(pc->rear == 99){
		printf("the confirmed list is already full.\n");
		pc->rear++;
	}
	//Empty Condition
	else if(pc->front == -1 && pc->rear == -1){
		pc->front++;
		pc->rear++;
	}
	else {
		pc->rear++;
	}
	pc->pa[pc->rear] = p;
}

int dequeue(struct waitingListQueue *pw){
	int temp=0;
	//Boundary Conditions
	if(pw->front == -1 && pw->rear == -1)temp=-1;
	
	else {
		temp = pw->pa[pw->front].pnr;
		pw->front++;
		if(pw->rear < pw->front){
			//Setting as empty queue
			pw->rear = -1;
			pw->front = -1;
		}
	}
	return (temp);
}

int isFull(struct waitingListQueue w){
	if(w.rear == 99)return 1;
	else return 0;
}

int isEmpty(struct waitingListQueue w){
	if(w.front == -1 && w.rear == -1)return 1;
	else return 0;
}

int search(struct confirmedListQueue c,int pt){
	int rt = -1;
	if(c.front > -1 && c.rear > -1){
		for(int i=c.front;i<c.rear+1;i++){
			if(c.pa[i].pnr == pt){
				rt = i;
				break;
			}
		}
	}
	return rt;
}

void print(struct waitingListQueue w,struct confirmedListQueue c){
	//Empty check
	if(w.front == -1 && w.rear == -1){
		printf("Waiting List is Empty.\n");
	}
	else {
		printf("\nPassengers in the waiting list are,\n");
		for(int i=w.front;i<w.rear+1;i++){
			printf("Passenger %d :\n\t\tPNR  : %d\n\t\tName : %s\n\t\tFare : %d\n",i+1-w.front,w.pa[i].pnr,w.pa[i].name,w.pa[i].fare);
		}
		printf("\n\n");
	}
	if(c.front == -1 && c.rear == -1){
		printf("Confirmed List is Empty.\n");
	}
	else {
		printf("\nPassengers in the confirmed list are,\n");
		for(int j=c.front;j<c.rear+1;j++){
			printf("Passenger %d :\n\t\tPNR  : %d\n\t\tName : %s\n\t\tFare : %d\n",j+1-c.front,c.pa[j].pnr,c.pa[j].name,c.pa[j].fare);
		}
		printf("\n\n");
	}
}


