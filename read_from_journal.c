#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct {
	int day;
	char date[11];
	char content[1500];
	char v;
}Entry;

typedef struct {
	int password;
}Cryptt;


int numberr(FILE* f, int l)
{
	long p; int n;
	p = ftell(f); 
	fseek(f, 0, 2); 
	n = ftell(f) / l;
	fseek(f, p, 0); 
	return n;
}

void main()
{
	FILE* f, *g;
	Cryptt C;
	Entry E;
	int p;
	int n = 0;
	char dat;
	printf("\nPassword: "); scanf("%d", &p);
	printf("\nWhat date do you want to read from? "); getchar(); gets(dat);
	f = fopen("crypt", "rb");
	if (f == NULL)
	{
		printf("!ERROR!");
	}
	else
	{
		g = fopen("myfile", "rb");
		if (g == NULL)
		{
			printf("!ERROR!");
		}
		else
		{
			while (n < numberr(g, sizeof(Entry)))
			{
				fseek(g, n * sizeof(Entry), 0);
				fread(&E, sizeof(Entry), 1, g);
				if ((E.v == 1) && (strcmp(E.date, dat) == 0))
				{
					printf("\nOn %s you wrote '%s' ", E.date, E.content);
				}
				else printf("\nNo entry found.");
				n++;
			}
		}
		fclose(g);
	}
	fclose(f);
}
