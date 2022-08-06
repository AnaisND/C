#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


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
	int p;
	char buffer[2000];
	printf("\nPassword: "); scanf("%d", &p);
	f = fopen("crypt", "rb");
	if (f == NULL)
	{
		printf("!ERROR!");
	}
	else
	{
		g = fopen("myfile", "r");
		if (g == NULL)
		{
			printf("!ERROR!");
		}
		else
		{
			while (fscanf(g, "%s", buffer) != EOF)
			{
				printf("%s", buffer);
			}
		}
		fclose(g);
	}
	fclose(f);
}
