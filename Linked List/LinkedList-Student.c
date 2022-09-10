#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

struct Student
{
	char name[100];
	int id;
	int grade;

	struct Student* next;
	struct Student* prev;
};
struct Student* head;
struct Student* tail;

void pPrint()
{
	struct Student* currentStudent = head;
	struct Student* printStudent;

	
	while (currentStudent != NULL)
	{
		printStudent = currentStudent;
		printf("\nStudent's information: name, id, grade:\n");
		printf("Name:%s id:%d grade:%d\n", printStudent->name, printStudent->id, printStudent->grade);
		currentStudent = currentStudent->next;
	}
}

void fFree()
{
	struct Student* currentStudent = head;
	struct Student* release;

	while (currentStudent != NULL)
	{
		release = currentStudent;
		currentStudent = currentStudent->next;
		free(release);
	}
}


int main_4()
{
	struct Student* newStudent;
	struct Student* previousStudent = NULL;

	for (int i = 0; i < 5; i++)
	{
		newStudent = (struct Student*)malloc(sizeof(struct Student));
		if (newStudent == NULL)
		{
			printf("ERROR - not enough memory");
			return;
		}
		else
		{
			printf("Please enter the student's information: name, id and grade:\n");
			scanf("%s %d %d", newStudent->name, &newStudent->id, &newStudent->grade);

			if (head == NULL)
			{
				head = newStudent;
				tail = newStudent;
				newStudent->prev = NULL;
				newStudent->next = NULL;
			}
			else
			{
				newStudent->prev = previousStudent;
				newStudent->next = NULL;
				previousStudent->next = newStudent;
				tail = newStudent;
			}

			previousStudent = newStudent;
		}
	}
	
	pPrint();
	fFree();

	return 0;
}