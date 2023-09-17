#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }

    node() {}
};

node *front = NULL;
node *rear = NULL;

void enqueue(int x)
{
    node *t = new node(x);
    if (t == NULL)
    {
        cout << "queue is already full" << endl;
    }
    else
    {
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

void dequeue()
{
    node *p = new node();

    if (front == NULL)
    {
        cout << "queue is already empty" << endl;
    }
    else
    {
        p = front;
        front = front->next;
        free(p);
    }
}

void print()
{
    node *p = front;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    print();
    dequeue();
    print();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}