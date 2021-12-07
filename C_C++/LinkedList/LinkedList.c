#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void InsertAtBeg(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
    
}

void InsertAtIndex(int x, int index) {
    if(index < 0) return;
    if(index == 0) return InsertAtBeg(x);

    struct Node* temp = head;//(struct Node*)malloc(sizeof(struct Node));
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    // temp->data = x;
    int i;
    for(i = 0; i < index - 1; i++) {
        if(temp->next == NULL) {
            printf("index out of bounds\n");    
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    
}

void ReverseIter() {
    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void Delete(int index) {
    struct Node* temp = head;
    if(index < 0) return;
    printf("%d\n", temp->data);
    int i;
    for(i = 0; i < index - 1; i++) {
        if(temp->next == NULL || temp->next->next == NULL) {
            printf("index out of bounds\n");    
            return;
        }
        temp = temp->next;
    }
    struct Node* toDelete = temp->next;
    if(index == 0) {
        toDelete = head;
        head = temp->next;
        return;
    }
    temp->next = temp->next->next;
    free(toDelete);
}

void Print() {
    struct Node* temp = head;
    printf("List is: ");
    while(temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void PrintRecur(struct Node* p) {
    if(p == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", p->data);
    PrintRecur(p->next);
}

void PrintRecurReverse(struct Node* p) {
    if(p == NULL) {
        return;
    }
    PrintRecurReverse(p->next);
    printf("%d ", p->data);
}

void ReverseRecur(struct Node* p) {
    if(p->next == NULL) {
        head = p;
        return;
    }
    ReverseRecur(p->next);
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

int main() {
    int n, i;
    n = 17;
    for(i = 0; i < n; i++) {
        InsertAtBeg(i);
        Print();
    }
    ReverseRecur(head);
    Print(head);
}
