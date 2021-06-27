#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node* head;

void Insert1(int data);
void Insert2(int data);
void Delete(int n);
void Reverse();
void Reverse_Recursive(struct Node* p);
void Print();
void Print_Recursive(struct Node* temp);
void Print_Reverse(struct Node* temp);
void Reverse_Recursive(struct Node* p)  // RECURSIVE FUNCTION TO REVERSE A SINGLY LINKED LIST (it will not print)
{
	if(p->next == NULL)
	{
		head = p;
		return;
	}
	
	Reverse_Recursive(p->next); // p is the addres of the previous node
	p->next->next = p;
	p->next = NULL;
}
void Print_Reverse(struct Node* temp)   //PRINT THE LIST IN REVERSE ORDER USING RECURSION
{
	if (temp == NULL)  // BASE CASE
	{
		printf("\n");
		return;
	}
	
	Print_Reverse(temp->next); //RECURSIVE CALL
	printf("%d ",temp->data);
}
void Print_Recursive(struct Node* temp)  //PRINT THE LIST IN THE SAME ORDER USING RECURSION
{
	if (temp == NULL)
	{
		printf("\n");
		return;
	}
	
	printf("%d ",temp->data); // WE FIRST DE-REFERENCE THE ADDRESS AND THEN GO TO THE DATA FIELD THERE
	Print_Recursive(temp->next);
}
void Print() // PRINT THE LIST	
{
	struct Node* temp = head;
	printf("\nThe list is: ");
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void Insert1(int data)   // INSERT AT BEGINNING OF THE LIST
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = head;
	head = temp;
}
void Insert2(int data)  // INSERT AT THE END OF THE LIST
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	struct Node* temp2 = head;
	while(temp2->next != NULL) // TO REACH TO THE END OF THE LIST
	{
		temp2 = temp2->next;
	}
	temp2->next = temp;
}

void Delete (int n)
{
	struct Node* temp = head;
	if (n==1) //DELETE FIRST NODE
	{
		head = temp->next;
		free(temp);
		return;
	}
	//DELETE INTERMEDIATE NODES 
	int i;
	for(i=0; i<n-2; i++)
	{
		temp = temp->next;
	}
	struct Node* temp1 = temp->next;
	temp->next = temp1->next;
	free(temp1);
}
void Reverse()             // REVERSING LIST USING ITERATIVE METHOD (it will not print)
{
	struct Node *prev, *current, *nxt;
	current = head;
	prev = NULL;
	while(current != NULL)
	{
		nxt = current->next;
		current->next = prev;
		prev = current;
		current = nxt;
	}
	head = prev;
}
int main()
{
	head = NULL;
	int n;
	Insert1(2);
	Insert1(4);
	Insert2(5);
	Insert2(5);
	Insert2(6);
	Insert1(1);
	printf("\nThe list is: ");
	Print_Recursive(head);
	printf("Enter position to delete node: ");
	scanf("%d",&n);
	Delete(n);
	printf("\nThe list after deletion of a node: ");
	Print();
	//Reverse();
	printf("\nReversed List is: ");
	Reverse_Recursive(head);
	Print();
	//Print_Reverse(head);
	printf("\n");
	return 0;
}
