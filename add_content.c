#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct {
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
	int p;
	int n;
	printf("\nPassword: "); scanf("%d", &p);
	f = fopen("crypt", "rb");
	if (f == NULL)
	{
		printf("!ERROR!");
	}
	else
	{
		rewind(f);
		fread(&C, sizeof(Cryptt), 1, f);
		if (p == C.password)
		{
			g = fopen("myfile", "a");
			if (g == NULL)
			{
				printf("!ERROR!");
			}
			else
			{
				printf("\nToday's date: "); getchar(); gets(E.date);
				printf("\nThe content of your entry: "); getchar(); gets(E.content);
				fprintf(g, "\nDate: %s   %s", E.date, E.content);
			}
			fclose(g);
		}
	}
	fclose(f);
}
