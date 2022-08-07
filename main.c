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


void CREATE(FILE* f, FILE* g, char n1[], char n2[])
{
	Cryptt C;
	Entry E;
	int entry;
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
		g = fopen("myfile", "wb+");
		if (g == NULL)
		{
			printf("!ERROR!");
		}
		else
		{
			printf("\nEntry number: "); scanf("%d", &entry);
			while (!feof(stdin))
			{
				if (entry >= entries(g, L))
				{
					E.v = 0;
					fseek(g, 0, 2);
					for (int i = entries(g, L); i <= entry; i++)
					{
						fwrite(&E, L, 1, g);
					}
				}
				fseek(g, entry * L, 0);
				fread(&E, L, 1, g);
				if (E.v)
				{
					printf("\nThis entry already exists.");
				}
				else
				{
					fseek(g, entry * L, 0);
					printf("\nToday's date: "); getchar(); gets(E.date);
					printf("\nThe content of this entry: "); getchar(); gets(E.content);
					E.v = 1;
					fwrite(&E, L, 1, g);
				}
				printf("\nEntry number: "); scanf("%d", &entry);
			}
		}
		fclose(g);
	}
	fclose(f);
}

void ADD(FILE* f, FILE* g, char n1[], char n2[])
{
	Cryptt C;
	Entry E;
	int p;
	int entry;
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
			g = fopen("myfile", "ab+");
			if (g == NULL)
			{
				printf("!ERROR!");
			}
			else
			{
				printf("\nEntry number: "); scanf("%d", &entry);
				while (!feof(stdin))
				{
					if (entry >= entries(g, L))
					{
						E.v = 0;
						fseek(g, 0, 2);
						for (int i = entries(g, L); i <= entry; i++)
						{
							fwrite(&E, L, 1, g);
						}
					}
					fseek(g, entry * L, 0);
					fread(&E, L, 1, g);
					if (E.v)
					{
						printf("\nThis entry already exists.");
					}
					else
					{
						fseek(g, entry * L, 0);
						printf("\nToday's date: "); getchar(); gets(E.date);
						printf("\nThe content of this entry: "); getchar(); gets(E.content);
						E.v = 1;
						fwrite(&E, L, 1, g);
					}
					printf("\nEntry number: "); scanf("%d", &entry);
				}
				fclose(g);
			}
		}
	}
	fclose(f);
}


void READ(FILE* f, FILE *g, FILE *h, char n1[], char n2[], char n3[])
{
	Cryptt C;
	Entry E;
	int p, n;
	printf("\nPassword: "); scanf("%d", &p);
	f = fopen(n1, "rb");
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
			g = fopen(n2, "rb+");
			if (g == NULL)
			{
				printf("\n!ERROR!");
			}
			else
			{
				h = fopen(n3, "w");
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

void main()
{
	FILE* A, * B, * C;
	char n1[] = "crypt", n2[] = "myfile", n3[] = "memories";
	CREATE(&A, &B, n1, n2);
	ADD(&A, &B, n1, n2);
	READ(&A, &B, &C, n1, n2, n3);
}
