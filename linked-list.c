#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *head = NULL;


void create( int d)
{
	if(head==NULL)
	{
		head = (struct node *)malloc(sizeof(struct node));
		head->data=d;
		head->link=NULL;
	}
	else
	{
		struct node *newNode;
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->data = d;
		newNode->link = NULL;
		
		struct node *temp = head;
		while(temp->link != NULL){
		  temp = temp->link;
		}
		
		temp->link = newNode;
	}
	printf("Inserted\n");
}

void atbegin(int t)
{
	if(head==NULL)
	{
		head = (struct node *)malloc(sizeof(struct node));
		head->data=t;
		head->link=NULL;
	}
	else
	{
		struct node *newNode;
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->data = t;
		newNode->link = head;
		
		//struct node *temp = head;
		head = newNode;
	}
}

void atposition(int a, int d)
{
	if(a==0)
	{
		atbegin(d);
	}
	else
	{
		struct node *temp = head;
		for(int i=0;i<a-1;i++)
		{
			temp = temp->link;
			if(temp==NULL)
			{
				
				printf("%d position is greater than size: error in linked list length", d);
				return;
			}
			
		}
		struct node *curr = (struct node *)malloc(sizeof(struct node));
		curr->data = d;
		curr->link = temp->link;
		temp->link = curr;
	}
	
}

void traverse()
{
	struct node *temp = head;
	printf("\n\nList elements are - \n");
	while(temp != NULL) {
	  printf("--->%d ",temp->data);
	  temp = temp->link;
	}
}




int main(){
	
	
	create(5);
	create(51);
	create(52);
	atbegin(4);
	atposition(2,89);
	traverse();
	

	
	/*	head->data = 45;
		head->link = NULL;
		
		printf("%d", head->data);*/
	return 0;
}
