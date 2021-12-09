#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void Push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int Pop() {
    struct Node* temp;
    if (top == NULL) return;
    temp = top;
    top = top->next;
    int res = temp->data;
    free(temp);
    return res;
}

int main() {
    int i;
    for(i = 0; i < 10; i++) {
        Push(2 * i);
    }
    while(top != NULL) {
        printf("%d\n", Pop());
    }
}