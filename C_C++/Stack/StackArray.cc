#include <stdio.h>
#include <stdlib.h>

class StackArray
{

#define MAX_SIZE 101
    int A[MAX_SIZE];
    int top;

public:
    StackArray()
    {
        top = -1;
    }

    void Push(int x)
    {
        if (top == MAX_SIZE - 1)
        {
            printf("Error: stack overflow ;)\n");
            return;
        }
        A[++top] = x;
    }

    int Pop()
    {
        if (top == -1)
        {
            printf("Error: No element to pop\n");
            return INT_MIN;
        }
        return A[top--];
    }

    int Top()
    {
        return top;
    }
};

int main()
{
    StackArray s;

    s.Push(5);
    s.Push(19);
    s.Push(11);

    int i;
    while (s.Top() != -1)
    {

        printf("%d\n", s.Pop());
    }
}