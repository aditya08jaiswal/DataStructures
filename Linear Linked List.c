//Linear Linked List

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
	
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	
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
	}
	
	else
	{
		struct Node* newtemp;
	
		newtemp = head;
		head = temp;
		
		temp->next = newtemp;
	}
	
	printf("First node successfully added!\n");
}

void InsertInBetween()
{
	struct Node* temp, *newtemp;
	int loc,len,i=1;
	
	printf("Enter location : ");
	scanf("%d",&loc);
	
	len = StrengthOfStudents();
	
	if(loc > len)
	{
		printf("Invalid location!\n");
		printf("Current list is having %d nodes.\n",len);		
	}
	
	else
	{
		newtemp = head;
		
		while(i < loc)
		{
			newtemp = newtemp->next;
			i++;		
		}	
		
		temp = (struct Node*) malloc(sizeof(struct Node));
		
		printf("\nEnter Roll No. : ");
		scanf("%d",&temp->rollno);
	
		printf("Enter Name : ");
		scanf("%s",temp->name);
	
		printf("Enter CGPA : ");
		scanf("%d",&temp->cgpa);
		printf("\n");
		
		temp->next = NULL;
		
		temp->next = newtemp->next;
		
		newtemp->next = temp;
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
		head = temp;
	}
	
	else
	{
		struct Node* p;
		
		p = head;
		
		while(p->next != NULL)
		{
			p = p->next;
		}	
		
		p->next = temp;
	}
	
	printf("Last node successfully added!\n");
}

void DeleteFirstNode()
{
	struct Node* temp;
	
	temp = head;
	
	if(temp==NULL)
	{
		printf("The list is EMPTY!\n");
	}

	else
	{
		head = temp->next;	
		temp->next = NULL;		//To completely free this deleted node 
		free(temp);
		
		printf("First node successfully deleted!\n");	
	}
}

void DeleteAnyNode()
{
	struct Node* temp;
	int loc;
	
	temp = head;
	
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

			newtemp->next = NULL;

			free(newtemp);

			printf("Selected node successfully deleted!");					
		}		
	}
}

void DeleteLastNode()
{
	struct Node* temp, *newtemp;
	int size,i=1;
	
	temp=head;

	if(temp==NULL)
	{
		printf("The list is EMPTY!\n");
	}
	
	else
	{
		size = StrengthOfStudents();
		
		while(i < size-1)
		{
			temp = temp->next;
			i++;
		}
	
		newtemp = temp->next;
	
		temp->next = NULL;
	
		free(newtemp);

		printf("Last node successfully deleted!");
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

void Display()
{
	struct Node* temp;
	
	temp  = head;

	if(temp == NULL)
	{
		printf("List is EMPTY!\n\n");
	}
	
	else
	{
		while(temp != NULL)
		{
			printf("\nRoll no. : %d",temp->rollno);
			printf("\nName : %s",temp->name);
			printf("\nCGPA : %d\n",temp->cgpa);
			
			temp = temp->next;
		}
	}
}

int main()
{
	int option, x=1;
	
	while(x=1)
	{
		printf("\n---------------------------------------------------");
		printf("\n1) Insert in front.\n2) Insert in between.\n3) Insert at the end.\n4) Strength of Students.\n5) Delete first node.\n6) Delete any node.\n7) Delete last node.\n8) Display.\n9) Search by Roll no.\n10) Exit.\n");
	
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

			case 4: StrengthOfStudents();
			break;
			
			case 5: DeleteFirstNode();
			break;
			
			case 6: DeleteAnyNode();
			break;
			
			case 7: DeleteLastNode();
			break;
			
			case 8: Display();
			break;
			
			case 9: Search();
			break;
			
			case 10: exit(0);
			break;
		}
	}

	return 0;
}

