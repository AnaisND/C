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


void main()
{
	FILE* f, *g;
	Cryptt C;
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
		g = fopen("myfile", "wb");
		if (g == NULL)
		{
			printf("!ERROR!");
		}
		fclose(g);
	}
	fclose(f);
}
