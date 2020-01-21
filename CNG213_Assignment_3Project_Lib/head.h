#include<stdio.h>
#include <stdlib.h> 

// Priority queue
typedef struct node{
    int data;
    int priority;
    int size;
    struct node* next;

}Node;

Node* newNode(int d, int p){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->size=0;
    temp->next = NULL;
    return temp;
}


int peek(Node** head){
    return (*head)->data;
}


void pop(Node** head){
	(*head)->size=(*head)->size-1;
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
    
}

void push(Node** head, int d, int p){
	(*head)->size=(*head)->size+1;
    Node* start = (*head);
    Node* temp = newNode(d, p);
    while (start->next != NULL &&
        start->next->priority < p) {
        start = start->next;
    }
    temp->next = start->next;
    start->next = temp;
}

int isEmpty(Node** head){
    return (*head) == NULL;
}

