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

}PURCHASE;

int nr_of_items(FILE* f, int l)
{
    long p;
    int n;
    p = ftell(f);
    fseek(f, 0, 2);
    n = ftell(f) / l;
    fseek(f, p, 0);
    return n;
}

void inv()
{
    FILE* f;
    PURCHASE P;
    srand(time(NULL));
    int L = sizeof(PURCHASE);
    int n;
    f = fopen("inventory", "ab+");
    if (f != NULL)
    {
        printf("\nItem's number: "); scanf("%d", &n);
        while (!feof(stdin))
        {
            if (n >= nr_of_items(f, L))
            {
                P.v = 0;
                fseek(f, 0, 2);
                for (int i = nr_of_items(f, L); i < n; i++)
                {
                    fwrite(&P, L, 1, f);
                }
            }
            fseek(f, n * L, 0);
            fread(&P, L, 1, f);
            if (P.v == 1)
            {
                printf("\nAn item already has the order number you entered. Please try again.");
            }
            else
            {
                fseek(f, n * L, 0);
                P.item_id = rand(); //Instead of names items get a random id, n is the order that the item is positioned in the inventory.
                printf("\nPrice of the item #%d: ", n); scanf("%d", &P.price);
                printf("\nQuantity of the item #%d: ", n); scanf("%d", &P.Q);
                printf("\nPoints for the item #%d: ", n); scanf("%d", &P.points);
                P.v = 1;
                fwrite(&P, L, 1, f);
                printf("\nSummary for #%d: %d, %d, %d, %d.", n, P.item_id, P.price, P.Q, P.points);
                printf("\nItem's number: "); scanf("%d", &n);
            }
        }
    }
    fclose(f);
}

void update_inv()
{
    FILE* f;
    PURCHASE P;
    int n, Q;
    int L = sizeof(PURCHASE);
    f = fopen("inventory", "rb+");
    if (f != NULL)
    {
        printf("\nItem's number: "); scanf("%d", &n);
        printf("\nPurchased quantity: "); scanf("%d", &Q);
        while (!feof(stdin))
        {
            if (n >= nr_of_items(f, L))
            {
                printf("\nItem doesn't exist.");
            }
            else
            {
                fseek(f, n * L, 0);
                fread(&P, L, 1, f);
                if (P.v == 1)
                {
                    printf("\nOld quantity: %d", P.Q);
                    P.Q = P.Q - Q;
                    printf("\nNew quantity: %d", P.Q);
                    fseek(f, n * L, 0);
                    fwrite(&P, L, 1, f);
                    printf("\nItem's number: "); scanf("%d", &n);
                    printf("\nPurchased quantity: "); scanf("%d", &Q);
                }
                else
                {
                    printf("\nItem doesn't exist.");
                }
            }
        }
    }
    fclose(f);
}


void edit_inv()
{
    FILE* f;
    PURCHASE P;
    int n;
    int L = sizeof(PURCHASE);
    f = fopen("inventory", "rb+");
    if (f != NULL)
    {
        printf("\nItem's number: "); scanf("%d", &n);
        while (!feof(stdin))
        {
            if (n >= nr_of_items(f, L))
            {
                printf("\nItem doesn't exist.");
            }
            else
            {
                fseek(f, n * L, 0);
                fread(&P, L, 1, f);
                if (P.v == 1)
                {
                    printf("\nNew price of the item #%d: ", n); scanf("%d", &P.price);
                    printf("\nNew quantity of the item #%d: ", n); scanf("%d", &P.Q);
                    printf("\nNew points for the item #%d: ", n); scanf("%d", &P.points);
                    fseek(f, n * L, 0);
                    fwrite(&P, L, 1, f);
                    printf("\nItem's number: "); scanf("%d", &n);
                }
                else
                {
                    printf("\nItem doesn't exist.");
                }
            }
        }
    }
    fclose(f);
}
