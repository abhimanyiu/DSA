#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int n)
    {
        data = n;
        next = NULL;
    }

    node() {}
};

node *top = NULL;

void push(int x)
{
    node *t = new node(x);

    if (t == NULL)
    {
        cout << "stack is full\n";
    }
    else
    {
        t->next = top;
        top = t;
    }
}

void pop()
{
    node *t = new node;
    if (top == NULL)
    {
        cout << "stack is empty!\n";
    }
    else
    {
        t = top;
        top = top->next;
        free(t);
    }
}

void print()
{
    node *x = top;
    if (x == NULL)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        while (x != NULL)
        {
            cout << x->data << " ";
            x = x->next;
        }
        cout << endl;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    pop();
    print();
    return 0;
}