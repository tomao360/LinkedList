#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

struct Item
{
	int val;
	struct Item* next;
};
struct Item* head = NULL;


//Print the list of numbers that the user entered
void PrintList()
{
	struct Item* currentItem = head;
	struct Item* thePrintNumber;

	printf("\nThe list of numbers that the user entered:\n");
	while (currentItem != NULL)
	{
		thePrintNumber = currentItem;
		printf("%d\n", thePrintNumber->val);
		currentItem = currentItem->next;
	}
}

//How many times the number 44 appears in the list
void Find44()
{
	struct Item* currentItem = head;
	int count = 0;

	while (currentItem != NULL)
	{
		if (currentItem->val == 44)
		{
			count++;
		}

		currentItem = currentItem->next;
	}

	printf("\nThe number 44 appears in the list %d times\n", count);
}

//Locate the id in the structers
void findID(int id)
{
	struct Item* currentItem = head;
	struct Item* ID;

	while (currentItem != NULL)
	{
		ID = currentItem;

		if (ID->val == id)
		{
			printf("The number: %d was located in this location:\n %d\n", ID->val, &currentItem->next);
		}

		currentItem = currentItem->next;
	}
}
/*
	struct Item* currentItem = head;
	struct Item* ID;
	int count = 1; //starts with 1 because the first structure

	while (currentItem != NULL)
	{
		ID = currentItem;

		if (ID->val == id)
		{
			printf("The id: %d was located in structer: %d\n", ID->val, count);
		}

		currentItem = currentItem->next;
		count++;
	}
*/

//Free the pointers
void freeList()
{
	struct Item* currentItem = head;
	struct Item* releaseItem;

	while (currentItem != NULL)
	{
		releaseItem = currentItem;
		currentItem = currentItem->next;
		free(releaseItem);
	}
}


int main()
{
	struct Item* currentItem;
	struct Item* prevItem = NULL;

	int num;
	printf("Please enter any number (if you want to exit enter 100) + ENTER\n");
	scanf("%d", &num);

	while (num != 100)
	{
		currentItem = (struct Item*) malloc(sizeof(struct Item));
		if (!currentItem)
		{
			printf("ERROR - not enough memory");
			return;
		}

		if (head == NULL)
		{
			head = currentItem;
		}
		else
		{
			prevItem->next = currentItem;
		}

		currentItem->val = num;
		printf("Please enter any number (if you want to exit enter 100) + ENTER\n");
		scanf("%d", &num);
		
		currentItem->next = NULL;
		prevItem = currentItem;
	}

	PrintList();
	Find44();

	int id;
	printf("\nPlease enter the number that you want to search in the structers + ENTER\n");
	scanf("%d", &id);
	findID(id);

	return 0;
}
