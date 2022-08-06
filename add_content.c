#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct {
	int day;
	char* date;
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
			g = fopen("myfile", "wb");
			if (g == NULL)
			{
				printf("!ERROR!");
			}
			else
			{
				printf("\nHow many days of having a journal have passed? "); scanf("%d", &n);
				while (!feof(stdin))
				{
					if (n >= numberr(g, sizeof(Entry)))
					{
						E.v = 0; 
						fseek(g, 0, 2);
						for (int i = numberr(g, sizeof(Entry)); i <= n; i++)
							fwrite(&E, sizeof(Entry), 1, g);
					}
					fseek(g, n * sizeof(Entry), 0); 
					fread(&E, sizeof(Entry), 1, g);
					if (E.v) printf("\nYou have already written today!");
					else {
						fseek(g, n * sizeof(Entry), 0);
						printf("\nToday's date: ");
						getchar(); gets(E.date);
						printf("\nThe content of your entry (maximum 1500 characters): ");
						getchar(); gets(E.content);
						E.v = 1; 
						fwrite(&E, sizeof(Entry), 1, g);
					}
					printf("\nHow many days of having a journal have passed? "); scanf("%d", &n);
				}
			}
			fclose(g);
		}
	}
	fclose(f);
}
