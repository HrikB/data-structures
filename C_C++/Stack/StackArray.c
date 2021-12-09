#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x) {
    if(top == MAX_SIZE - 1) {
        printf("Error: stack overflow ;)\n");
        return;
    }
    A[++top] = x;
}

int Pop() {
    if(top == -1) {
        printf("Error: No element to pop\n");
        return;
    }
    return A[top--];
}

int main() {
    Push(5);
    Push(19);
    Push(11);

    int i;
    while(top != -1) {
        
        printf("%d\n", Pop());
    }
}