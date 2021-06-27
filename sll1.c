#include<stdlib.h>
#include<stdio.h>

struct Node {
	
	int data;
	struct Node* next;
};

//struct Node* head; // global variable, can be accesed anywhere

// IF WE ARE NOT PASSING HEAD AS THE GLOBAL VARIABLE THEN WE WILL HAVE TO PASS HEAD AS THE ARGUMENT TO THE PRINT() FUNCTION AND THEN THERE IS NO NEED TO HAVE ANOTHER TEMP IN THE PRINT() BECAUSE THE VALUE OF HEAD WILL BE COPIED INTO THERE AND NOT THE ORIGINAL VALUE.

// SINCE, AFTER WE MODIFY THE LINKED LIST, THE HEAD IN MAIN SHOULD ALSO BE MODIFIED, THEREFORE THE INSERT() SHOULD RETURN THE POINTER TO HEAD NODE 

void Insert(int x, struct Node** head); // function definitions
void Print(struct Node* head);

// INSERT AT THE BEGINNING OF THE LINKED LIST
void Insert (int x, struct Node** pointertohead) // SO INSERT FUNCTION WILL HAVE TO RECEIVE A POINTER TO POINTER AND THE RETURN TYPE CAN NOW BE VOID
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;    // (*temp).data = x; would also work
	temp->next = *pointertohead; // if head == NULL then the node will be inserted as the first element
	*pointertohead = temp; 
	//return head;
}

void Print(struct Node* temp)
{
	//struct Node* temp = head;
	while (temp != NULL)
	{
		printf( "%d ", temp->data);
		temp = temp->next;
	}
}

int main()
{
	struct Node* head = NULL; // empty list
	int i, n, x;
	printf ("\nEnter the length of the list: ");
	scanf ("%d",&n);
	for (i=0; i<n; i++)
	{
		printf("\nEnter the element to be inserted: ");
		scanf("%d", &x);
		Insert(x, &head); // WE WILL HAVE TO COLLECT THE RETURN INTO HEAD AGAIN SO THAT IT IS MODIFIED
					// SINCE HEAD IS ALREADY A POINTER TO NODE, JUST PASS &HEAD TO INSERT FUNCTION 
	}
	printf("\n");
	Print(head);
	printf("\n");
	
	return 0;
}

