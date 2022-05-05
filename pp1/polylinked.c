#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int expo;
    struct Node *next;
};

void readPolynomial(struct Node **poly)
{
    int coeff, exp, cont;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    *poly = temp;
    do
    {
        printf("\n Coeffecient: ");
        scanf("%d", &coeff);
        printf("\n Exponent: ");
        scanf("%d", &exp);
        temp->coeff = coeff;
        temp->expo = exp;
        temp->next = NULL;
        printf("\nHave more terms? 1 for y and 0 for no: ");
        scanf("%d", &cont);
        if (cont)
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->next = NULL;
        }
    } while (cont);
}

void displayPolynomial(struct Node *poly)
{
    printf("\nPolynomial expression is: ");
    while (poly != NULL)
    {
        printf("%dX^%d", poly->coeff, poly->expo);
        poly = poly->next;
        if (poly != NULL)
            printf("+");
    }
}

void addPolynomials(struct Node **result, struct Node *first, struct Node *second)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = NULL;
    *result = temp;
    while (first && second)
    {
        if (first->expo > second->expo)
        {
            temp->coeff = first->coeff;
            temp->expo = first->expo;
            first = first->next;
        }
        else if (first->expo < second->expo)
        {
            temp->coeff = second->coeff;
            temp->expo = second->expo;
            second = second->next;
        }
        else
        {
            temp->coeff = first->coeff + second->coeff;
            temp->expo = first->expo;
            first = first->next;
            second = second->next;
        }

        if (first && second)
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->next = NULL;
        }
    }
    while (first || second)
    {
        temp->next = (struct Node *)malloc(sizeof(struct Node));
        temp = temp->next;
        temp->next = NULL;

        if (first)
        {
            temp->coeff = first->coeff;
            temp->expo = first->expo;
            first = first->next;
        }

        else if (second)
        {
            temp->coeff = second->coeff;
            temp->expo = second->expo;
            second = second->next;
        }
    }
}

int main()
{

    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *result = NULL;

    printf("\nEnter the corresponding data:-\n");
    printf("\nFirst polynomial:\n");
    readPolynomial(&first);
    displayPolynomial(first);
    printf("\n\nSecond polynomial:\n");
    readPolynomial(&second);
    displayPolynomial(second);
    addPolynomials(&result, first, second);
    printf("\n\nRESULT:\n");
    displayPolynomial(result);
    return 0;
}
