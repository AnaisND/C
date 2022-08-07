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

int L = sizeof(Entry);

int entries(FILE* f, int l)
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
	FILE* f, * g, *h;
	Cryptt C;
	Entry E;
	int p, n;
	printf("\nPassword: "); scanf("%d", &p);
	f = fopen("crypt", "rb");
	if (f == NULL)
	{
		printf("\n!ERROR!");
	}
	else 
	{
		rewind(f);
		fread(&C, sizeof(Cryptt), 1, f);
		if (p == C.password)
		{
			g = fopen("myfile", "rb+");
			if (g == NULL)
			{
				printf("\n!ERROR!");
			}
			else
			{
				h = fopen("memories", "w");
				if (h == NULL)
				{
					printf("\n!ERROR!");
				}
				else
				{
					n = 0;
					fread(&E, L, 1, g);
					while (!feof(g))
					{
						if (E.v)
						{
							fprintf(h, "\n%s:   '%s'", E.date, E.content);
						}
						n++;
						fread(&E, L, 1, g);
					}
				}
				fclose(h);
			}
			fclose(g);
		}
	}
	fclose(f);
}
