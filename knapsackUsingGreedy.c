#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char name;
	float profit;
	float weight;
	float ratio;
	struct node *next;
	struct node *prev;

}node;

node* createnode(char name,float profit,float weight)
{
    node *newnode;


    newnode=(node*)malloc(sizeof(node));
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->name=name;
    newnode->profit=profit;
    newnode->weight=weight;
    newnode->ratio=profit/weight;
    return newnode;
};

void displaynode(node *head)
{
	while(1)
	{
		printf("%c\t%.2f\t%.2f\t%.2f\n", head->name,head->profit,head->weight,head->ratio);
		if(head->next==NULL)
		{
			break;
		}
		else
		{
			head=head->next;
		}
	}

}

node* insert()
{
	node *head,*newnode;
	char name ='A';
	int profit,weight,headcheck=1;

	while(1)
	{
		printf("\nEnter the profit of \"%c\" object \n",name);
		scanf("%d",&profit);
		printf("\nEnter the weight of \"%c\" object \n",name);
		scanf("%d",&weight);
		if(headcheck)
		{
			head=createnode(name,profit,weight);
			newnode=head;
			headcheck=0;
		}
		else
		{
			newnode->next=createnode(name,profit,weight);
			newnode->next->prev=newnode;
			newnode=newnode->next;

		}
		name++;
		printf("\nDo you want to enter more  Y/N...\n");
		if(getch()!='y')
		{
			break;
		}

	}
	return head;
};

node* maxratio(node *head)
{

	node *max;
	max=head;
	while(1)
	{

		if(max->ratio<head->ratio)
		{
			max=head;
		}

			if(head->next!=NULL)
			{
				head=head->next;
			}
			else
			{
				break;
			}

	}

	if(max->next==NULL && max->prev==NULL)
	{
		return max;
	}
	else if (max->prev==NULL)
	{
		max->next->prev=NULL;
	}
	else if (max->next!=NULL)
	{

		max->prev->next=max->next;
	}
	else
	{

		max->prev->next=NULL;

	}



	return max;
};



void main()
{
	node *head,*max;
	float netprofit=0,netweight=0;
	float capacity=0,caprem=0;

	printf("Enter the capacity of the bag\n");
	scanf("%f",&capacity);

	head=insert();

	printf("-------------------------------------------\n");
	printf("\n\nTaking ");
	while(1)
	{
		max=maxratio(head);
		if (capacity>=max->weight)
		{
			capacity=capacity-max->weight;	
			netprofit=netprofit+max->profit;
			printf("\"%c\"  ",max->name );	

		}
		else if (capacity<1)
		{
			break;
		}
		else
		{
			caprem=max->weight/capacity;
			netprofit=netprofit+max->profit/caprem;
			printf("  %c/%.1f",max->name,caprem);
			break;
		}
	

		if (max==head)
		{
			if(head->next!=NULL)
				head=head->next;
			else
				break;
			
		}
	}

	printf("\n Hence getting Total profit of --  %.2f\n", netprofit);

}
