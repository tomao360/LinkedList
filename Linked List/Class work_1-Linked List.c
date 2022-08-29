#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

int main()
{
	struct Car
	{
		short barcode;
		int carNumber;
		int id;
	};

	int num;
	printf("Please enter the number of structers that you need\n");
	scanf("%d", &num);

	struct Car* currentCar;
	struct Car* list;

	currentCar = (struct Car*)malloc(sizeof(struct Car) * num);
	if (!currentCar)
	{
		printf("ERROR");
		return;
	}

	list = currentCar;

	for (int i = 0; i < num; i++)
	{
		printf("Pleas enter barcode, car number and id + ENTER\n");
		scanf("%hi %d %d", &currentCar->barcode, &currentCar->carNumber, &currentCar->id);

		currentCar++;
	}

	FILE* f = fopen("Exercise1.bin", "w");
	if (f != NULL)
	{
		fwrite(list, sizeof(struct Car), num, f);
		fclose(f);
	}
	else
	{
		printf("ERROR");
	}

	free(list);


	return 0;
}