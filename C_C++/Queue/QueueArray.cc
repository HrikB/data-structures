#include <stdio.h>
#include <stdlib.h>

class QueueArray
{
#define MAX_SIZE 101

private:
    int front, end, size;
    int A[MAX_SIZE];

public:
    QueueArray()
    {
        front = -1;
        end = -1;
        size = 0;
    }

    void Enqueue(int x)
    {
        if (size == MAX_SIZE)
            return;
        else if (isEmpty())
            front = end = 0;
        else
            end = (end + 1) % MAX_SIZE;

        A[end] = x;
        size++;
    }

    int Dequeue()
    {
        if (isEmpty())
            return INT_MIN;
        int item = A[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        return item;
    }

    int Peek()
    {
        return A[front];
    }

    int isEmpty()
    {
        if (front == -1 && end == -1)
        {
            return 1;
        }
        return 0;
    }

    void Print()
    {
        for (int i = front; i < front + size; i++)
        {
            printf("%d ", A[i % MAX_SIZE]);
        }
        printf("\n");
    }
};

int main()
{
    QueueArray q;
    for (int i = 0; i < 101; i++)
    {
        q.Enqueue(i);
        q.Print();
    }

    for (int i = 0; i < 50; i++)
    {
        int res = q.Dequeue();
        printf("res: %d; ", res);
        q.Print();
    }

    for (int i = 150; i < 200; i++)
    {
        q.Enqueue(i);
        q.Print();
    }
}