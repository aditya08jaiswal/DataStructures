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

/*
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

	if(root == NULL)
	{
		root = temp;
	}

	else
	{
		struct node* p;		//for traversing through the node, we are using another var.

		p = root;		//initializing it to root to tarverse from start point

		while (p->right != NULL)
		{
			p = p->right;
		}

		p->right = temp;	//connecting forward
		temp->left = p;		//connecting backward
	}
}
*/
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

/*
int StrengthOfStudents()
{
	struct node*  temp = root;
	int count = 0;

	while(temp !=NULL)
	{
		count++;
		temp = temp->right;		//traversing forward
	}

	return count;
}

void Display()
{
	struct node*  temp = root;

	if(temp == NULL)
	{
		printf("\nList is EMPTY!");
	}

	else
	{
		while(temp !=NULL)
		{
			printf("\nRoll no. : %d", temp->rollno);
			printf("\nName : %s", temp->name);
			printf("\nCGPA : %d", temp->cgpa);

			temp = temp->right;	//traversing forward
		}
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

		p = root;	//Another pointer for traversal

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

	temp = root;

	if (temp == NULL)
	{
		printf("\nThe list is EMPTY!");
	}

	else
	{
		root = temp->right;
		temp->right = NULL;
		free(temp);
		printf("\nNode successfully DELETED!");
	}
}

void DeleteAnyNode()		//left
{
	struct node* temp = root, *newtemp = (struct node*) malloc(sizeof(struct node));

	int loc, len=StrengthOfStudents();

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

			free(newtemp);

			printf("Node successfully DELETED!");
		}

		else
		{
			DeleteFirstNode();
		}
	}
}

void DeleteLastNode()		//else is left
{
	struct node* temp;
	int len = StrengthOfStudents();

	temp = root;

	if (temp == NULL)
	{
		printf("\nThe list is EMPTY!");
	}

	else
	{
		while (temp->right != NULL)
		{
			temp = temp->right;
		}

		if(len >= 2)
		{
			temp->left->right = NULL;	//temp->left(address of preceeding node). When right is used, it points to the address of node to be deleted.
		}

		else					//if list has only one node, then we don't need above line of code. Since, no backward(left) pointer is present.
		{
			temp->left = NULL;
		}

		free(temp);

		printf("\nLast node deleted SUCCESSFULLY!");
	}
}

void Search()
{
	struct Node* temp;
	int rn, count=0;

	temp = head;

	printf("Enter Roll no. to search the student : ");
	scanf("%d",&rn);

	while(temp != NULL)
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

	if(count == StrengthOfStudents())
	{
		printf("NO result found!\n");
	}
}



*/

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
