//Linear Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int rollno;
	char name[30];
	int cgpa;
	struct Node* next;
};

struct Node* head = NULL;

int StrengthOfStudents()
{
	int count = 0;

	struct Node* temp;
	temp = head;

	if (head == NULL)
	{
		return 0;
	}

	do
	{
		count++;
		temp = temp->next;
	}
	while(temp != head);

	return count;
}

void InsertInFront()
{
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));

	printf("\nEnter Roll No. : ");
	scanf("%d",&temp->rollno);

	printf("Enter Name : ");
	scanf("%s",temp->name);

	printf("Enter CGPA : ");
	scanf("%d",&temp->cgpa);
	printf("\n");

	temp->next = NULL;

	if(head == NULL)		//list is empty
	{
		head = temp;
		temp->next = head; 	//connected to itself
	}

	else
	{
		struct Node* p;
		p = head;

		do	//for traversing and finding last element
		{
			p = p->next;
		}
		while(p->next != head);

		p->next = temp;	//connecting node at the end
		temp->next = head;	//connecting head and tail to make it circular
	}
	head = temp;
	printf("First node added SUCCESSFULLY!\n");
}

void InsertInBetween()	//left
{
	struct Node* temp, *newtemp;
	int loc,len,count=1;

	printf("Enter location : ");
	scanf("%d",&loc);

	len = StrengthOfStudents();

	if(loc > len)
	{
		printf("Invalid location!\n");
		printf("Current list is having %d nodes.\n",len);

		return;
	}

	else
	{
		newtemp = head;

		temp = (struct Node*) malloc(sizeof(struct Node));

		printf("\nEnter Roll No. : ");
		scanf("%d",&temp->rollno);

		printf("Enter Name : ");
		scanf("%s",temp->name);

		printf("Enter CGPA : ");
		scanf("%d",&temp->cgpa);
		printf("\n");

		temp->next = NULL;

		do
		{
			newtemp = newtemp->next;
			count++;
		}
		while(newtemp->next != head && loc != count);

		temp->next = newtemp->next;
		newtemp->next = temp;

		printf("Node in between added SUCCESSFULLY!\n");
	}
}

void InsertAtTheEnd()
{
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));

	printf("\nEnter Roll No. : ");
	scanf("%d",&temp->rollno);

	printf("Enter Name : ");
	scanf("%s",temp->name);

	printf("Enter CGPA : ");
	scanf("%d",&temp->cgpa);
	printf("\n");

	temp->next = NULL;

	if(head == NULL)		//list is empty
	{
		temp->next = temp; 	//pointing to itself
		head = temp;
	}

	else
	{
		struct Node* p;
		p = head;

		while(p->next != head)
		{
			p = p->next;
		}
		p->next = temp;	//connecting node at the end
		temp->next = head;	//connecting head and tail to make it circular
	}

	printf("Last node successfully added!\n");
}

void DeleteFirstNode()
{
	struct Node* temp = head;

	if(temp==NULL)
	{
		printf("The list is EMPTY!\n");
	}

	else
	{
		do
		{
			temp = temp->next;
		}
		while(temp->next != head);

		head = head->next;
		temp->next = head;		//To completely free this deleted node

		printf("First node successfully deleted!\n");
	}
}

void DeleteAnyNode()
{
	struct Node* temp = head;
	int loc;

	if(temp==NULL)
	{
		printf("The list is EMPTY!\n");
	}

	else
	{
		printf("Enter node no. to delete : ");
		scanf("%d",&loc);

		if(loc > StrengthOfStudents())
		{
			printf("Invalid location!\n");
		}

		else
		{
			struct Node* newtemp = head;
			int i=1;

			while(i < loc-1)
			{
				temp = temp->next;
				i++;
			}

			newtemp = temp->next;

			temp->next = newtemp->next;

			newtemp->next = head;

			printf("Selected node successfully deleted!");
		}
	}
}

void DeleteLastNode()
{
	struct Node* temp = head;
	int size,i=1;

	if(temp==NULL)
	{
		printf("The list is EMPTY!\n");
	}

	else if (head->next == NULL)
	{
		head = NULL;
	}

	else
	{
		size = StrengthOfStudents();

		while(i < size-1)
		{
			temp = temp->next;
			i++;
		}

		temp->next = head;	//giving address of first node to last second node

		printf("Last node successfully deleted!");
	}
}


void Search()
{
	if(head == NULL)
	{
		printf("Empty List\n");
		return;
	}

	else
	{
		struct Node* temp = head;

		int rn, count=0;

		printf("Enter Roll no. to search the student : ");
		scanf("%d",&rn);

		do
		{
			if(temp->rollno == rn)
			{
				printf("\nRoll no. : %d",temp->rollno);
				printf("\nName : %s",temp->name);
				printf("\nCGPA : %d",temp->cgpa);
			}

			else
			{
				count++;
			}

			temp =  temp->next;
		}
		while(temp != head);

		if(count == StrengthOfStudents())
		{
			printf("NO result found!\n");
		}
	}
}

void Display()
{
	struct Node* temp;
	temp  = head;

	if(temp == NULL)
	{
		printf("List is EMPTY!\n\n");
		return;
	}

	else
	{
		do
		{
			printf("\nRoll no. : %d",temp->rollno);
			printf("\nName : %s",temp->name);
			printf("\nCGPA : %d\n",temp->cgpa);

			temp = temp->next;
		}
		while(temp != head);
		printf("\n");
	}
}

int main()
{
	int option;

	while(1)
	{
		printf("\n---------------------------------------------------");
		printf("\n1) Insert in front.\n2) Insert in between.\n3) Insert at the end.\n4) Delete first node.\n5) Delete any node.\n6) Delete last node.\n7) Display.\n8) Search by Roll no.\n9) Exit.\n");

		printf("\nEnter option to start : ");
		scanf("%d",&option);

		printf("---------------------------------------------------\n");
		switch(option)
		{
			case 1:	InsertInFront();
			break;

			case 2: InsertInBetween();
			break;

			case 3: InsertAtTheEnd();
			break;

			case 4: DeleteFirstNode();
			break;

			case 5: DeleteAnyNode();
			break;

			case 6: DeleteLastNode();
			break;

			case 7: Display();
			break;

			case 8: Search();
			break;

			case 9: exit(0);
			break;
		}
	}

	return 0;
}
