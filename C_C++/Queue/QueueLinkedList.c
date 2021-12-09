#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* end = NULL;

void Enqueue(int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if(isEmpty()) {
        front = newNode;
        end = newNode;
        return;
    }
    end->next = newNode;
    end = newNode;
}

int Dequeue() {
    struct Node* temp = front;
    if(front == NULL) return INT_MIN;
    
 
    front = front->next;
    if(front == NULL) {
        end = NULL;
    }

    free(temp);
    return temp->data;

}

int Peek() {
    return end->data;
}

int isEmpty() {
    if(front == NULL && end == NULL) return 1;
    return 0;
}

//usually wouldn't have this, for debugging purposes
void Print() {
    struct Node* temp = front;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int i;
    for(i = 0; i < 101; i++) {
        Enqueue(i);
        Print();
    }


    for(i = 0; i < 50; i++) {
        int res = Dequeue();
        printf("res: %d; ", res);
        Print();
    }

    for(i = 150; i < 200; i++) {
        Enqueue(i);
        Print();
    }

}