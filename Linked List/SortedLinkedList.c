#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

struct Iitem
{
	int val;
	
	struct Iitem* next;
	struct Iitem* prev;
};
struct Iitem* HEAD = NULL;
struct Iitem* TAIL = NULL;

struct Iitem* findHigher(int val);
void LocateAfterTail(struct Iitem* item);
void LocateBeforeHead(struct Iitem* item);
void LocateBeforeItem(struct Iitem* newItem, struct Iitem* itemInList);

// Generate list with 10 random numbers
void GenerateList()
{
	struct Iitem* cuurentNumber;
	struct Iitem* previousNumber = NULL;

	time_t i = time();
	srand(i);

	for (int i = 0; i < 10; i++)
	{
		cuurentNumber = (struct Iitem*)malloc(sizeof(struct Iitem));
		if (cuurentNumber == NULL)
		{
			printf("ERROR - Not enough memory");
			return;
		}
		int a = rand();
		cuurentNumber->val = a;
		 
		if (HEAD == NULL)
		{
			HEAD = cuurentNumber;
			TAIL = cuurentNumber;
			cuurentNumber->next = NULL;
			cuurentNumber->prev = NULL;
		}
		else
		{
			TAIL = cuurentNumber;
			cuurentNumber->next = NULL;
			cuurentNumber->prev = previousNumber;
			previousNumber->next = cuurentNumber;
		}

		previousNumber = cuurentNumber;
	}
}

// Generate list with x random numbers
void GenerateXList(int x)
{
	struct Iitem* cuurentNumber;
	struct Iitem* previousNumber = NULL;

	time_t i = time();
	srand(i);

	for (int i = 0; i < x; i++)
	{
		cuurentNumber = (struct Iitem*)malloc(sizeof(struct Iitem));
		if (cuurentNumber == NULL)
		{
			printf("ERROR - Not enough memory");
			return;
		}
		int a = rand();
		cuurentNumber->val = a;

		if (HEAD == NULL)
		{
			HEAD = cuurentNumber;
			TAIL = cuurentNumber;
			cuurentNumber->next = NULL;
			cuurentNumber->prev = NULL;
		}
		else
		{
			TAIL = cuurentNumber;
			cuurentNumber->next = NULL;
			cuurentNumber->prev = previousNumber;
			previousNumber->next = cuurentNumber;
		}

		previousNumber = cuurentNumber;

	}
}

void printList()
{
	struct Iitem* thePrintNumber = HEAD;

	printf("\nThe resulting linked list is:\n");
	while (thePrintNumber != NULL)
	{
		printf("%d\n", thePrintNumber->val);
		thePrintNumber = thePrintNumber->next;
	}
}

void freeLIST()
{
	struct Iitem* cuurentNumber = HEAD;
	struct Iitem* releaseMeamory;

	while (cuurentNumber != NULL)
	{
		releaseMeamory = cuurentNumber;
		cuurentNumber = cuurentNumber->next;
		free(releaseMeamory);
	}
}

// Returns the address of the number that the user chose
struct Iitem* FindVal(int findVal)
{
	struct Iitem* cuurentNumber = HEAD;
	struct Iitem* ret = NULL;

	while (cuurentNumber != NULL)
	{
		if (cuurentNumber->val == findVal)
		{
			ret = cuurentNumber;
		}
		
		cuurentNumber = cuurentNumber->next;
	}

	return ret;
}

// Change a number with a new number
struct Iitem* ChangeVal(int oldVal, int newVal)
{
	struct Iitem* ret = FindVal(oldVal);

	if (ret != NULL)
	{
		ret->val = newVal;
	}

	return ret;
}

void ResetList()
{
	if (HEAD != NULL)
	{
		freeLIST();
		HEAD = NULL;
		TAIL = NULL;
	}
}



//////////////////////// Sorted Linked List

// This function will receive a number and allocate space in memory. This function will call all the other functions 
void AddItem(int newItem)
{
	struct Iitem* cuurentNumber;
	cuurentNumber = (struct Iitem*)malloc(sizeof(struct Iitem));
	if (cuurentNumber == NULL)
	{
		printf("ERROR - Not enough memory");
		return;
	}
	cuurentNumber->val = newItem;

	if (HEAD == NULL)
	{
		HEAD = cuurentNumber;
		TAIL = cuurentNumber;
		cuurentNumber->next = NULL;
		cuurentNumber->prev = NULL;
	}
	else
	{
		struct Iitem* highNumber = findHigher(cuurentNumber->val); // NULL מחפש את האיבר הגדול ביותר. אם הוא לא מצא אז זה אומר שהוא האיבר הגדול ביותר ולכן יחזיר 
		//not found higher, means that new item is the smallest

		if (highNumber == NULL)
		{
			LocateAfterTail(cuurentNumber);
		}
		else
		{
			if (highNumber == HEAD)
			{
				LocateBeforeHead(cuurentNumber);
			}
			else
			{
				LocateBeforeItem(cuurentNumber, highNumber);
			}
		}
	}
}

// This function will receive a number and find the first higher number relative to this number
// If the function will not find a smaller number it will return NULL
struct Iitem* findHigher(int val)
{
	struct Iitem* currentNumber = HEAD;
	struct Iitem* ret = NULL;

	while (currentNumber != NULL)
	{
		if (currentNumber->val > val) // If the value of currentNumber is bigger than the value of the parameter (the number that the user entered)
		{
			ret = currentNumber;
			return ret;
		}

		currentNumber = currentNumber->next;
	}

	return ret;
}

// A function that places the highest number in the tail
void LocateAfterTail(struct Iitem* item)
{
	item->next = NULL;
	item->prev = TAIL;
	TAIL->next = item;
	TAIL = item;
}

// A function that places the lowest number in the head
void LocateBeforeHead(struct Iitem* item)
{
	item->next = HEAD;
	item->prev = NULL;
	HEAD->prev = item;  
	HEAD = item;
}

// פונקציה שמטרתה למקם איבר משמאל לאיבר שגדול ממנו
void LocateBeforeItem(struct Iitem* newItem, struct Iitem* itemInList)
{
	itemInList->prev->next = newItem; // The next of the prev number will point to newItem
	newItem->prev = itemInList->prev;
	newItem->next = itemInList;
	itemInList->prev = newItem;
}



int main_5()
{
	// GenerateList();

	int num;
	printf("Please enter a number - this number will indicate how many times you would like to grill random numbers:\n");
	scanf("%d", &num);
	GenerateXList(num);

	printList();

	int num2;
	printf("\nPlease enter the number you are looking for:\n");
	scanf("%d", &num2);
	int* a = FindVal(num2);
	printf("The number located in this address:%p\n", a);


	int* b = ChangeVal(num2, 10);
	printf("\nThe new linked list with the new number:");
	printList();

	ResetList();


	//Sorted Linked List
	printf("\n");
	int num3;
	for (int i = 0; i < 10; i++)
	{
		printf("Please enter a number to the list + ENTER\n");
		scanf("%d", &num3);
		AddItem(num3);
	}
	printList();

	return 0;
} 