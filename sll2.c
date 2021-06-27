#include<stdio.h>
#include<stdlib.h>
							// INSERT NODE AT N'th POSITION 
struct Node{
	int data;
	struct Node* next;
};
struct Node* head;
void Insert(int x, int n);
void Print();
void Print()
{
	struct Node* temp = head;
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void Insert(int x, int n)
{
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = x;
	temp1->next = NULL;
	if (n==1) // INSERT NODE AT THE BEGINNING OF THE LIST
	{
		temp1->next = head;
		head = temp1;
		return;
	}
	struct Node* temp2 = head;
	for (int i=0; i<=n-3; i++)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}
int main()
{
	head = NULL;
	Insert(23,1);
	Insert(34,2);
	Insert(45,3);
	Insert(67,2);
	Print();
	return 0;	
}
