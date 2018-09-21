#include<stdio.h>
 void b(int *o);
 void a(int *p);
void main(){
	int y=2;
	int *py = &y;
	a(&y);
}

void a(int *p){
	b(&p);
}
void b(int *o){
if(*o==2)printf("HI");
}
