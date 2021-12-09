#include <stdio.h>
#include <stdlib.h>

class QueueLinkedList
{

    struct Node
    {
        int data;
        Node *next;
    };

private:
    Node *front;
    Node *end;

public:
    QueueLinkedList()
    {
        front = NULL;
        end = NULL;
    }

    void Enqueue(int x)
    {
        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;
        if (isEmpty())
        {
            front = newNode;
            end = newNode;
            return;
        }
        end->next = newNode;
        end = newNode;
    }

    int Dequeue()
    {
        Node *temp = front;
        if (front == NULL)
            return INT_MIN;

        front = front->next;
        if (front == NULL)
        {
            end = NULL;
        }

        delete temp;
        return temp->data;
    }

    int Peek()
    {
        return end->data;
    }

    int isEmpty()
    {
        if (front == NULL && end == NULL)
            return 1;
        return 0;
    }

    //usually wouldn't have this, for debugging purposes
    void Print()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
};

int main()
{
    QueueLinkedList q;

    int i;
    for (i = 0; i < 101; i++)
    {
        q.Enqueue(i);
        q.Print();
    }

    for (i = 0; i < 50; i++)
    {
        int res = q.Dequeue();
        printf("res: %d; ", res);
        q.Print();
    }

    for (i = 150; i < 200; i++)
    {
        q.Enqueue(i);
        q.Print();
    }
}