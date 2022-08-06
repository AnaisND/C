#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


typedef struct {
	int day;
	char date[11];
	char content[1500];
}Entry;

typedef struct {
	int password;
}Cryptt;


void main()
{
	FILE* f, * g;
	Cryptt C;
	Entry E;
	f = fopen("crypt", "wb");
	if (f == NULL)
	{
		printf("!ERROR!");
	}
	else
	{
		printf("\nCreate a password (numeric characters): ");
		scanf("%d", &C.password);
		fwrite(&C, sizeof(Cryptt), 1, f);
		g = fopen("myfile", "w");
		if (g == NULL)
		{
			printf("!ERROR!");
		}
		else
		{
			E.day = 0;
			printf("\nToday's date: "); getchar(); gets(E.date);
			printf("\nThe content of your first entry (maximum 1500 characters): "); getchar(); gets(E.content);
			fprintf(g, "\n%d Date: %s   '%s'",E.day, E.date, E.content);
		}
		fclose(g);
	}
	fclose(f);
}
