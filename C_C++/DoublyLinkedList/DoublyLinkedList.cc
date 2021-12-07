#include <stdio.h>
#include <stdlib.h>

class DoublyLinkedList
{

    struct Node
    {
        int data;
        struct Node *next;
        struct Node *prev;
    };
    Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void InsertAtHead(int x)
    {
        Node *newNode = GetNewNode(x);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void Print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    void ReversePrint()
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp->prev != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
        printf("\n");
    }

    void InsertAtTail(int x)
    {
        struct Node *newNode = GetNewNode(x);
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

private:
    Node *GetNewNode(int x)
    {
        Node *newNode;
        newNode = new Node;
        newNode->data = x;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
    }
};

int main()
{
    DoublyLinkedList dLL;
    int i;
    for (i = 0; i < 10; i++)
    {
        dLL.InsertAtHead(i);
    }
    dLL.InsertAtTail(15000);
    dLL.Print();
    dLL.ReversePrint();
}