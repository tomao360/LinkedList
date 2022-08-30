#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

struct Person
{
	short age;
	int phone;
	int id;
};

//Exercise 1
void myStructer()
{
	int num;
	printf("Please enter the number of structers that you need\n");
	scanf("%d", &num);

	struct Person* currentPerson;
	struct Person* list;

	currentPerson = (struct Person*)malloc(sizeof(struct Person) * num);
	if (!currentPerson)
	{
		printf("ERROR");
		return;
	}

	list = currentPerson;

	for (int i = 0; i < num; i++)
	{
		printf("Pleas enter barcode, car number and id + ENTER\n");
		scanf("%hi %d %d", &currentPerson->age, &currentPerson->phone, &currentPerson->id);

		currentPerson++;
	}

	FILE* f = fopen("Exercise1.bin", "w");
	if (f != NULL)
	{
		fwrite(list, sizeof(struct Person), num, f);
		fclose(f);
	}
	else
	{
		printf("ERROR");
	}

	free(list);
}

//Exercise 2 - read a friends file
void readFileStruct()
{
	struct MyStruct
	{
		int id;
		short symbol;
	};

	FILE* f = fopen("C:\\Users\\97252\\source\\repos\\Linked List\\linkedlist1-mavo.bin", "r");
	struct MyStruct* ptr = (struct MyStruct*)malloc(sizeof(struct MyStruct));

	if (f)
	{
		int sumID = 0;

		while (fread(ptr, sizeof(struct MyStruct), 1, f))
		{
			sumID = sumID + ptr->id;
		}

		printf("The Sum of the ID is: %d", sumID);
		fclose(f);
	}
	else
	{
	printf("ERROR");
	}
}

int main_1()
{
	myStructer();
	readFileStruct();

	return 0;
}