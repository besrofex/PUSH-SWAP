#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node 
{
    int data;
    struct Node *next;
};


// creat a node :
struct Node *newnode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// traverse and print the elements :
void traversallinkedlist(struct Node *head)
{
    struct Node *curr = head;
    while (curr != NULL)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}


// searching in Linkedlist :
bool SerachLinkedList(struct Node *head, int target)
{
    while (head != NULL)
    {
        if (head->data == target)
            return true;
        head = head->next;
    }
    return false;
}

// lenght of Linked List :
int lenghtLiskedList(struct Node *head)
{
    int totale;

    totale = 0;
    while (head != NULL)
    {
        totale++;
        head = head->next;
    }
    return totale;
}

// insert At Bergining:
struct Node *insertAtBegining(struct Node *head , int value)
{
    struct Node *curr;
    curr = newnode(value);
    curr->next = head;
    head = curr;
    return head;
}

// insert at the end:
struct Node *insertAtTheEnd(struct Node *head , int value)
{
    struct Node *curr;

    curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = newnode(value);
    return head;
}

//insert At A Specific Position :
struct Node *insertAtASpecificPos(struct Node *head, int pos, int value)
{
    struct Node *curr;
    struct Node *new_node;
    int i;

    if (pos == 1)
        return insertAtBegining(head,value);
    curr = head;
    i = 1;
    while(i < pos - 1 && curr != NULL)
    {
        curr = curr->next;
        i++;
    }
    if (curr == NULL)
        return insertAtTheEnd(head,value);
    new_node = newnode(value);
    new_node->next = curr->next;
    curr->next = new_node;
}


int main()
{
    int i;
    struct Node *curr;
    struct Node *head;

    head = newnode(10);
    i = 9;
    while (i >= 0)
    {
        curr = newnode(i);
        curr->next = head;
        head = curr;
        i--;
    }
    insertAtASpecificPos(head,3,100000);
    traversallinkedlist(head);
}
