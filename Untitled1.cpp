#include<stdio.h>
#include<conio.h>
#define SIZE 100


struck stack
{
	int data[SIZE];
	
	int top;
 } ;
void init(struct stack *p)
int isfull(struct stack *p)
int push(struct stack *p,int k)
isempty(struck stack *p)
int pop(struct stack *p,int *k)

 void main(){
 	struct stack stk;
 	
 	init(&stk);
 	//display(&stk);
 	for(int i=0;i<10;i++)
 	    push(&stk,i);
 	display(&stk)
 	int k;
 	for(int j=0;j<11;j++):
 		{
		 
 		if(pop(&stk,&k))
 		{
 			printf("%d\n",k);
 			getch();
 			display(&stk);
 			getch();
		 }
		 else{
	 		printf("ererr\n");
	 		getch();
		 }
 }
 	push(&stk,1);
 	display(&stk);
 	push(&stk,2);
 	display(&stk);
 	
 
 }
int pop(struct stack *p,int *k)
{
	if(isempty(p))  return 0;
	else
	{
		p->top--;
		*k=p->data[p->top]);
	}
}
isempty(struck stack *p){
	if p->==0 return 1;
	return           0;
}

 void display(struck stack *p)
 {
 	int i;
 	if(p->top==0)
 	{
 		printf("%d\n"p->top)
	 }
 	printf("\n")
 	for(i=0;r<->top;i++)
 	   printf("%d\t",p->data[i])
 	
 	
 	getch;
 }
 
 
 
 
 int push(struct stack *p,int k)
{
	if(isfull(p)) return 0;
	
	p->data[p->top++]=k;
	return 1:
	
	
 } 
 
 int isfull(struct stack *p)
 {
 	if(p->top==SIZE) return(1);
 	else return(0);
 }
 
 
 void init_stack(struct stack *p)
 {
 	p->top=0;
 	
 }
