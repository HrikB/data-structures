#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* GetNewNode(int x) {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int x) {
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void Print() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint() {
    struct Node* temp = head;
    if (temp == NULL) return; //empty list? -> exit
    //traverse to end
    while(temp->next != NULL) {
        temp = temp->next;
    }
    //traverse backwards using ->prev
    printf("Reverse: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void InsertAtTail(int x) {
    struct Node* newNode = GetNewNode(x);
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

int main() {
    int i;
    for(i = 0; i < 10; i++) {
        InsertAtHead(i);
    }
    InsertAtTail(15000);
    Print();
    ReversePrint();
}