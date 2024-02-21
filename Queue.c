#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //FOR DYNAMIC MEMORY ALLOCATION.
typedef struct node // SIMPLY CREATE A NODE USING STRUCTURE.
{
    int data;          // ONE PART IS DATA PART
    struct node *next; // ANOTHER IS ADDRESS PART REPRESENTED BY NEXT POINTER
} node;
/*CREATE LINKEDLIST USING STRUCTURE HAVING TW0 POINTER(REAR AND FRONT)
OF TYPE STRUCT NODE*/
typedef struct Queuelinkedlist
{
    struct node *rear;
    struct node *front;
} Queuelinkedlist;
/*WHENEVWE QUEUE IS EMPTY BOTH REAR AND FRONT ARE -1
IN THIS CASE OF LINKEDLIST BOTH REAR AND FRONT POINTER ARE INITIALIZED TO NULL*/
void initializequeue(Queuelinkedlist *QL)
{
    QL->rear = NULL;
    QL->front = NULL;
}
int isempty(Queuelinkedlist *QL)
{
    if (QL->rear == NULL && QL->front == NULL)
    {
        return 1; // WHEN TWO POINTER ARE NULL THEN QUEUE IS EMPTY.
    }
    else
    {
        return 0;
    }
}
void enqueue(Queuelinkedlist *QL, int element)
{
    // FIRST WE HAVE TO CREATE A NEWNODE DYNAMICALLY.
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    // THE ELEMENT IS STORED IN TO THE DATA PART OF THE NEWNODE.
    newnode->data = element;
    // THE NEXT PART OF THE NEWNODE IS INITILIZED TO NULL.
    newnode->next = NULL;
    if (isempty(QL))
    {
        /*WHEN EVER THE QUEUE IS EMPTY,AFTER THE CREATION OF NEW NODE ,
        BOTH REAR AND FRONT PONTERS ARE POINTS TO THE NEW NODE.*/
        QL->front = newnode;
        QL->rear = newnode;
        return;
    }
    else
    {
        /*WHEN THE ALREADY NODES ARE PRESENT IN QUEUE THE WE HAVE TO MOVE THE 
        REAR POINTER TO THE NEXT THEN THE REAR POINTER POINTS TO THE NEWNODE*/
        QL->rear->next = newnode;
        QL->rear = newnode;
    }
}
void display(Queuelinkedlist *QL)
{
    //WHEN THE QUEUE IS EMPTY THEN THERE IS NO ELEMENTS.
    if (isempty(QL))
    {
        return;
    }
    else
    {
        struct node *temp;//WE CREATE A TEMPORARY POINTER FOR TRAVERSAL
        temp = QL->front;/*FIRST TEMP POINTS TO THE FRONT OF THE QUEUE
        UP TO THE REAR OF THE QUEUE*/
        for (temp = QL->front; temp != QL->rear; temp = temp->next)
        {
            printf("%d<-", temp->data);
        }
    }
}
void dequeue(Queuelinkedlist *QL)
{
    /*WHEN THE QUEUE IS EMPTY THEN WE CAN NOT PERFORM DEQUEUE OPERATION*/
    if (isempty(QL))
    {
        return;
    }
    else
    {
        /*WHEN THE ALREADY NODES ARE PRESENT IN QUEUE THEN SIMPLY ,
        FRONT POINTS TO FORWORD.*/
        QL->front = QL->front->next;
    }
}
int main()
{
    Queuelinkedlist QL;
    initializequeue(&QL);
    isempty(&QL);
    //FUNCTION CALL OF THE ENQUEUE FUNCTION
    enqueue(&QL, 100);
    enqueue(&QL, 200);
    enqueue(&QL, 300);
    enqueue(&QL, 400);
    enqueue(&QL, 500);
    display(&QL);//FUNCTION CALL OF THE DISPLAY FUNCTION
    dequeue(&QL);
    printf("\n");
    display(&QL);
    getch();
    return 0;
}