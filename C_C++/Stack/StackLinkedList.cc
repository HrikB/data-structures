#include <stdio.h>
#include <stdlib.h>

class StackLinkedList
{
    struct Node
    {
        int data;
        Node *next;
    };

    Node *top;

public:
    StackLinkedList()
    {
        top = NULL;
    }

    void Push(int x)
    {
        Node *temp = new Node;
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    int Pop()
    {
        Node *temp;
        if (top == NULL)
            return INT_MIN;
        temp = top;
        top = top->next;
        int res = temp->data;
        delete temp;
        return res;
    }

    Node *Top()
    {
        return top;
    }
};

int main()
{
    StackLinkedList s;

    int i;
    for (i = 0; i < 10; i++)
    {
        s.Push(2 * i);
    }
    while (s.Top() != NULL)
    {
        printf("%d\n", s.Pop());
    }
}