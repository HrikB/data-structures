#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
int A[MAX_SIZE];

int front = -1;
int end = -1;
int size = 0;


void Enqueue(int x) {
    if(size == MAX_SIZE) return;
    else if(isEmpty()) front = end = 0;
    else end = (end + 1) % MAX_SIZE;

    A[end] = x;
    size++;
}

int Dequeue() {
    if(isEmpty()) return INT_MIN;
    int item = A[front];
    front = (front + 1) % MAX_SIZE;
    size--;
    return item;
}

int Peek() {
    return A[front];
}

int isEmpty() {
    if(front == -1) {
        if(end == -1) return 1; //&& not working??
    }
    return 0;
}

void Print() {
    int i;
    for (i = front; i < front + size; i++) {
        printf("%d ", A[i % MAX_SIZE]);
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