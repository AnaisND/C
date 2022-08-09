#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include "inventory.h"
#include "card.h"


void hmainh()
{
	int choice;
	printf("\nPress 1 for entering data into the inventory.");
	printf("\nPress 2 for editing data inside the inventory.");
	printf("\nPress 3 for a client's card registration."); //You can also register clients who haven't made a purchase if you add them 0 points.
	printf("\nPress 4 for a purchase without the fidelity card.");
	printf("\nPress 5 for a purchase with the fidelity card.");
	printf("\nPress 6 to exit.\n");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
		inv();
		break;
	case 2:
		edit_inv();
		break;
	case 3:
		registration();
		break;
	case 4:
		update_inv();
		break;
	case 5:
		update_card();
		break;
	case 6:
		exit(0);
	default:
		printf("\n!ERROR!");
	}
}
