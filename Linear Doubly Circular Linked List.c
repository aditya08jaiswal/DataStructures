//Linear Doubly Circular Linked List

#include<stdio.h>
#include<stdlib.h>


struct node
{
	struct node* left;
	int rollno, cgpa;
	char name[30];
	struct node* right;
};

struct node* head = NULL;
struct node* tail = NULL;

void InsertAtTheEnd()
{
	struct node* temp;

	temp = (struct node*) malloc(sizeof(struct node));

	temp->left = NULL;

	printf("Enter Roll no. : ");
	scanf("%d",&temp->rollno);

	printf("Enter name : ");
	scanf("%s",temp->name);

	printf("Enter CGPA : ");
	scanf("%d",&temp->cgpa);

	temp->right = NULL;

	if(head == NULL)
	{
		temp->right = temp;
		temp->left = temp;
		head = temp;
	}

	else
	{
		tail = head->left;	//getting last node
		temp->right = head;	//connecting new node's right to head - forward
		temp->left = tail;	//connecting new node's left to tail - backward
		tail->right = temp;	//connecting tail's right to temp - backward
		head->left = temp;	//connecting forward the head and new node
	}
}

void InsertInFront()
{
	struct node* temp = (struct node*) malloc(sizeof(struct node));

	temp->left = NULL;

	printf("Enter Roll no. : ");
	scanf("%d",&temp->rollno);

	printf("Enter name : ");
	scanf("%s",temp->name);

	printf("Enter CGPA : ");
	scanf("%d",&temp->cgpa);

	temp->right = NULL;

	if(head == NULL)
	{
		temp->left = temp;
		temp->right = temp;
	}

	else
	{
	//	will connect right node first else whole structure data will be lost, since root will not further point to whole data structure
		temp->right = head;
		head->left = temp;
		temp->left = tail;
		tail->right = temp;
	}

		head = temp;
		tail = head->left;
}


int StrengthOfStudents()
{
	struct node*  temp = head;
	int count = 0;

	do
	{
		count++;
		temp = temp->right;		//traversing forward
	}
	while(temp != head);

	return count;
}


void Display()
{
	struct node* temp = head;

	if(temp == NULL)
	{
		printf("\nList is EMPTY!");
	}

	else
	{
		do
		{
			printf("\n************************************************\n");
			printf("\nRoll no. : %d", temp->rollno);
			printf("\nName : %s", temp->name);
			printf("\nCGPA : %d", temp->cgpa);

			temp = temp->right;	//traversing forward
		}
		while(temp != head);

		printf("\n************************************************\n\n");
	}
}

void InsertInBetween()
{
	struct node* temp, *p;
	int loc, len=StrengthOfStudents(), i=1;

	printf("Enter loaction to add : ");
	scanf("%d",&loc);

	loc--;		//to set element on particular position entered

	if(loc > len)
	{
		printf("\nInvalid location.");
		printf("\nList contains only : %d elements.",len);
	}

	else
	{
		temp = (struct node*) malloc(sizeof(struct node));

		temp->left = NULL;

		printf("Enter Roll no. : ");
		scanf("%d",&temp->rollno);

		printf("Enter name : ");
		scanf("%s",temp->name);

		printf("Enter CGPA : ");
		scanf("%d",&temp->cgpa);

		temp->right = NULL;

		p = head;	//Another pointer for traversal

		while(i<loc)
		{
			p = p->right;
			i++;
		}

		temp->right = p->right;		//connecting forward - right side of temp
		p->right->left = temp;		//connecting backward pointer to pointer - right side of temp
		temp->left = p;			//connectng backward - left side of temp
		p->right = temp;		//connectng forward - left side of temp
	}
}

void DeleteFirstNode()
{
	struct node* temp;

	temp = head;

	if (temp == NULL)
	{
		printf("\nThe list is EMPTY!");
	}

	else
	{
		head = temp->right;
		temp->right = NULL;
		tail->right = head;

		printf("\nNode successfully DELETED!");
	}
}

void DeleteAnyNode()		//left
{
	struct node* temp = head, *newtemp = (struct node*) malloc(sizeof(struct node));

	int loc, len=StrengthOfStudents();

	if(temp==NULL)
	{
		printf("The list is EMPTY!\n");
	}

	else
	{
		printf("Enter node no. to delete : ");
		scanf("%d",&loc);

		if(loc > len)
		{
			printf("Invalid location!\n");
		}

		else if (len >= 2)
		{
			int i=1;

			while(i < loc-1)
			{
				temp = temp->right;
				i++;
			}

			newtemp = temp->right;	//newtemp initially points to node to be deleted

			temp->right = newtemp->right;
			newtemp->left = temp;

			printf("Node successfully DELETED!");
		}

		else
		{
			DeleteFirstNode();
		}
	}
}

void DeleteLastNode()
{
	struct node* temp;
	int len = StrengthOfStudents();

	temp = head;

	if (temp == NULL)
	{
		printf("\nThe list is EMPTY!");
	}

	else
	{
		while (temp->right != head)
		{
			temp = temp->right;
		}

		if(len >= 2)
		{
			temp->left->right = head;	//temp->left(address of preceeding node). When right is used, it points to the address of node to be deleted.
			temp->left = NULL;
		}

		else					//if list has only one node, then we don't need above line of code. Since, no backward(left) pointer is present.
		{
			temp->left = NULL;
			head = NULL;
		}

		free(temp);

		printf("\nLast node deleted SUCCESSFULLY!");
	}
}

void Search()
{
	struct node* temp;
	int rn, count=0, len=StrengthOfStudents();

	temp = head;

	if (temp==NULL)
	{
		printf("No data to search\n");
		return;
	}

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

		temp = temp->right;
	}
	while(temp != head);

	if(count == len)
	{
		printf("NO result found!\n");
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
