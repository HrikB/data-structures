#include <stdio.h>

class LinkedList
{

    struct Node
    {
        int data;
        Node *next;
    };
    Node *head;

public:
    LinkedList() //attribute
    {
        head = NULL;
    }

    void InsertAtBeg(int x)
    {
        Node *temp = new Node;
        temp->data = x;
        temp->next = head;
        head = temp;
    }

    void InsertAtIndex(int x, int index)
    {
        if (index < 0)
            return;
        if (index == 0)
            return InsertAtBeg(x);
        Node *temp = head;
        Node *newNode = new Node;
        newNode->data = x;
        for (int i = 0; i < index - 1; i++)
        {
            if (temp->next == NULL)
            {
                printf("index out of bounds\n");
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void Delete(int index)
    {
        struct Node *temp = head;
        if (index < 0)
            return;
        printf("%d\n", temp->data);
        int i;
        for (i = 0; i < index - 1; i++)
        {
            if (temp->next == NULL || temp->next->next == NULL)
            {
                printf("index out of bounds\n");
                return;
            }
            temp = temp->next;
        }
        struct Node *toDelete = temp->next;
        if (index == 0)
        {
            toDelete = head;
            head = temp->next;
            return;
        }
        temp->next = temp->next->next;
        delete toDelete;
    }

    void ReverseIter()
    {
        Node *prev, *curr, *next;
        prev = NULL;
        curr = head;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void Print()
    {
        Node *temp = head;
        printf("List is: ");
        while (temp != NULL)
        {
            printf(" %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    //helper function
    void PrintRecur()
    {
        PrintRecur(head);
    }

    void PrintRecurReverse()
    {
        PrintRecurReverse(head);
    }

    void ReverseRecur()
    {
        ReverseRecur(head);
    }

private:
    void PrintRecur(struct Node *p)
    {
        if (p == NULL)
        {
            printf("\n");
            return;
        }
        printf("%d ", p->data);
        PrintRecur(p->next);
    }

    void PrintRecurReverse(struct Node *p)
    {
        if (p == NULL)
        {
            return;
        }
        PrintRecurReverse(p->next);
        printf("%d ", p->data);
    }

    void ReverseRecur(struct Node *p)
    {
        if (p->next == NULL)
        {
            head = p;
            return;
        }
        ReverseRecur(p->next);
        struct Node *q = p->next;
        q->next = p;
        p->next = NULL;
    }
};

int main()
{
    int n = 17;
    LinkedList l;
    for (int i = 0; i < n; i++)
    {
        l.InsertAtBeg(i);
        l.Print();
    }
    l.ReverseRecur();
    l.PrintRecurReverse();
}