//  Single Linked List 
#include <stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node* link;
};
struct node* head = NULL;
 
// Function to traverse the linked list
void traverse()
{
    struct node* temp;
 
    if (head == NULL)
        printf("\nList is empty\n");
 
    else {
        temp = head;
        while (temp != NULL) {
            printf("Data = %d\n",
                   temp->info);
            temp = temp->link;
        }
    }
}
 
// insert at the front

void insertAtFront()
{
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
    temp->info = data;
 
    
    temp->link = head;
    head = temp;
}
 
// insert at the end

void insertAtEnd()
{
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
 
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
 
    temp->link = 0;
    temp->info = data;
    head = head;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}
 
//  insert at any specified

void insertAtPosition()
{
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
 
    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);
 
    temp = head;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1) {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}
 
// Delete from the front
void deleteFirst()
{
    struct node* temp;
    if (head == NULL)
        printf("\nList is empty\n");
    else {
        temp = head;
        head = head->link;
        free(temp);
    }
}
 
//  Delete from the end
void deleteEnd()
{
    struct node *temp, *prevnode;
    if (head == NULL)
        printf("\nList is Empty\n");
    else {
        temp = head;
        while (temp->link != 0) {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
    }
}
 
//  Delete from any specified
void deletePosition()
{
    struct node *temp, *position;
    int i = 1, pos;
 
    
    if (head == NULL)
        printf("\nList is empty\n");
 
    
    else {
        printf("\nEnter index : ");
 
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = head;
 
        while (i < pos - 1) {
            temp = temp->link;
            i++;
        }
 
        position = temp->link;
        temp->link = position->link;
 
        free(position);
    }
}
 

int main()
{
    int choice;
    while (1) {
 
        printf("\n\t1  To see list\n");
        printf("\t2  For insertion at"
               " starting\n");
        printf("\t3  For insertion at"
               " end\n");
        printf("\t4  For insertion at "
               "any position\n");
        printf("\t5  For deletion of "
               "first element\n");
        printf("\t6  For deletion of "
               "last element\n");
        printf("\t7  For deletion of "
               "element at any position\n");
        printf("\t8 To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
 
        switch (choice) {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteFirst();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            deletePosition();
            break;
        case 8:
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}