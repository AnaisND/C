#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>


typedef struct
{
    int item_id;
    int price;
    int Q; //quantity
    int points; //nr of points you get for buying this item.
    char v;

}PURCHASE2;

typedef struct
{
    char fname[30];
    char lname[30];
    char exp_date[10];
    char mob[20];
    int points;
    char v;
}CARD;

int nr_of_clients(FILE* f, int l)
{
    long p;
    int n;
    p = ftell(f);
    fseek(f, 0, 2);
    n = ftell(f) / l;
    fseek(f, p, 0);
    return n;
}

void registration()
{
    FILE* f;
    CARD C;
    int L = sizeof(CARD);
    int n;
    f = fopen("card_registration", "ab+");
    if (f != NULL)
    {
        printf("\nClient's number: "); scanf("%d", &n);
        while (!feof(stdin))
        {
            if (n >= nr_of_clients(f, L))
            {
                C.v = 0;
                fseek(f, 0, 2);
                for (int i = nr_of_clients(f, L); i < n; i++)
                {
                    fwrite(&C, L, 1, f);
                }
            }
            fseek(f, n * L, 0);
            fread(&C, L, 1, f);
            if (C.v == 1)
            {
                printf("\nA client already has the id you entered. Please try again.");
            }
            else
            {
                fseek(f, n * L, 0);
                printf("\nFirst name: "); getchar(); gets(C.fname, 30);
                printf("\nLast name: "); getchar(); gets(C.lname);
                printf("\nCard expires on: "); getchar(); gets(C.exp_date);
                printf("\nMob. number: "); getchar(); gets(C.mob);
                printf("\nPoints earned for the first purchase: "); scanf("%d", &C.points);
                C.v = 1;
                fwrite(&C, L, 1, f);
                printf("\nSummary for client #%d: %s, %s, %s, %s, %d.", n, C.fname, C.lname, C.exp_date, C.mob, C.points);
                printf("\nClient's number: "); scanf("%d", &n);
            }
        }
    }
    fclose(f);
}

void update_card()
{
    FILE* f, * g;
    PURCHASE2 P2;
    CARD C;
    int L1 = sizeof(PURCHASE2), L2 = sizeof(CARD);
    int n1, n2, points = 0, Q;
    f = fopen("inventory", "rb+");
    g = fopen("card_registration", "rb+");
    if ((f != NULL) && (g != NULL))
    {
        printf("\nClient's number: "); scanf("%d", &n2);
        printf("\nItem's number: "); scanf("%d", &n1);
        printf("\nPurchased quantity: "); scanf("%d", &Q);
        while (!feof(stdin))
        {
            if (n1 >= nr_of_clients(f, L1))
            {
                printf("\nItem doesn't exist.");
            }
            else
            {
                fseek(f, n1 * L1, 0);
                fread(&P2, L1, 1, f);
                if (P2.v == 1)
                {
                    printf("\nOld quantity: %d", P2.Q);
                    P2.Q = P2.Q - Q;
                    points = points + P2.points;
                    printf("\nNew quantity: %d", P2.Q);
                    fseek(f, n1 * L1, 0);
                    fwrite(&P2, L1, 1, f);
                    printf("\nItem's number: "); scanf("%d", &n1);
                    printf("\nPurchased quantity: "); scanf("%d", &Q);
                }
                else
                {
                    printf("\nItem doesn't exist.");
                }
            }
        }
        printf("\nTotal earned points: %d", points);
        if (n2 < nr_of_clients(g, L2))
        {
            fseek(g, n2 * L2, 0);
            fread(&C, L2, 1, g);
            if (C.v == 1)
            {
                printf("\nOld points: %d", C.points);
                C.points = C.points + points;
                printf("\nNew points: %d", C.points);
                fseek(g, n2 * L2, 0);
                fwrite(&C, L2, 1, g);
            }
        }
    }
    fclose(f);
    fclose(g);
}
