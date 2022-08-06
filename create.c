#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct {
	char password[30];
	char date[11];
	char content[1500];
}Entry;
void main()
{
	FILE* f;
	Entry E;
	int i;
	f = fopen("myfile", "wb");
	printf("\nCreate a password (maximum 30 characters): ");
	getchar(); gets(E.password);
	printf("\nToday's date: ");
	getchar(); gets(E.date);
	printf("\nThe content of your first entry (maximum 1500 characters): ");
	getchar(); gets(E.content);
	fwrite(&E, sizeof(Entry), 1, f);
	fclose(f);
}
