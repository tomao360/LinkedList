#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

struct Item1
{
	int id;
	int val;
	struct Item1* next; //יכיל את הכתובת של הבא בתור
};
struct Item1* head1 = NULL; 

void freeLinkedList()
{
	struct Item1* currentItem = head1;
	struct Item1* releaseItem = head1;

	while (currentItem != NULL)
	{
		releaseItem = currentItem;
		currentItem = currentItem->next;
		free(releaseItem);
	}
}

int main_2()
{
	int userResponse;
	printf("Click 1 for Add\n Click 2 for Print All List\n Click 3 for EXit\n");
	scanf("%d", &userResponse);

	struct Item1* currentItem;
	struct Item1* prevItem = NULL;

	while (userResponse == 1)
	{
		currentItem = malloc(sizeof(struct Item1)); 

		if (head1 == NULL) 
		{
			head1 = currentItem; //צריך להידרך פעם אחת, הוא צריך להחזיק את האיבר הראשון וכל השאר ישתרשרו אליו head-ה 
		}
		else
		{
			prevItem->next = currentItem; //שהאיבר הקודם יצביע על האיבר החדש

		}

		scanf("%d %d", &currentItem->id, &currentItem->val);
		currentItem->next = NULL; //בגלל שאין עדיין את האיבר הבא

		printf("Click 1 for Add\n Click 2 for Print All List\n Click 3 for EXit\n");
		scanf("%d", &userResponse);


		prevItem = currentItem; //משווה את הכתובות כדי להביא את הכתוב, של הקודם לכתובת הנוכחית
	}

	freeLinkedList();
	return 0;
}