#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void sum(struct node *, int, struct node *, int);
void diff(struct node *, int, struct node *, int);
int min(int i, int j)
{
    return i < j ? i : j;
}
int max(int i, int j)
{
    return i > j ? i : j;
}

int main()
{
    struct node *newnode, *temp, *start = NULL, *ptr, *start1 = NULL;
    char c;
    int i = -1, j = -1, tem;
    printf("Enter the coefficients of the  first polynomial. Enter n/N to stop.\n");
    if (scanf("%c", &c) != 1)
    {
        printf("Error reading input.\n");
        return 1; // or handle the error appropriately
    }
    while (c != 'n')
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = (int)c - 48;
        if (start == NULL)
        {
            start = newnode;
            newnode->next = NULL;
            temp = start;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        i++;
        scanf(" %c", &c);
    }
    printf("Entered polynomial is:\n");
    tem = i;
    ptr = start;
    while (ptr->next != NULL)
    {
        printf("%dx^%d+", ptr->data, tem--);

        ptr = ptr->next;
    }
    printf("%d", ptr->data);

    printf("\nEnter the coefficients of the second polynomial. Enter n/N to stop.\n");
    scanf(" %c", &c);
    while (c != 'n')
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = (int)c - 48;
        if (start1 == NULL)
        {
            start1 = newnode;
            newnode->next = NULL;
            temp = start1;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        j++;
        scanf(" %c", &c);
    }
    tem = j;

    printf("Entered polynomial is:\n");

    ptr = start1;
    while (ptr->next != NULL)
    {
        printf("%dx^%d+", ptr->data, tem--);

        ptr = ptr->next;
    }
    printf("%d", ptr->data);
    printf("\nsum of the polynomials is: \n");
    if (i > j)
        sum(start, i, start1, j);
    else
        sum(start1, j, start, i);

    printf("\nDifference of the polynomials is .\n");
    if (i > j)
        diff(start, i, start1, j);
    else
        diff(start1, j, start, i);
    return 0;
}

void sum(struct node *start1, int i, struct node *start2, int j)
{
    if (i == j)
    {
        while (start1->next != NULL)
        {
            printf("%dx^%d+", (start1->data) + (start2->data), i--);
            start1 = start1->next;
            start2 = start2->next;
        }
        printf("%d", (start1->data) + (start2->data));
    }
    else
    {
        while (start1->next != NULL)
        {
            if (i > j)
                printf("%dx^%d+", (start1->data), i--);
            else
                printf("%dx^%d+", (start1->data) + (start2->data), i--);
            start1 = start1->next;
            start2 = start2->next;
        }
        printf("%d", (start2->data) + (start1->data));
    }
}
void diff(struct node *start1, int i, struct node *start2, int j)
{
    if (i == j)
    {
        while (start1->next != NULL)
        {
            printf("%dx^%d+", (start1->data) - (start2->data), i--);
            start1 = start1->next;
            start2 = start2->next;
        }
        printf("%d", (start1->data) - (start2->data));
    }
    else
    {
        while (start1->next != NULL)
        {
            if (i > j)
                printf("%dx^%d+", (start1->data), i--);
            else
                printf("%dx^%d+", (start1->data) - (start2->data), i--);
            start1 = start1->next;
            start2 = start2->next;
        }
        printf("%d", (start2->data) - (start1->data));
    }
}