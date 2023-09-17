#include <iostream>
using namespace std;

class queue
{
public:
    int front;
    int rear;
    int size;
    int *q;

    queue()
    {
        front = -1;
        rear = -1;
        size = 10;
        q = new int[10];
    }

    queue(int s)
    {
        front = rear = -1;
        size = s;
        q = new int[size];
    }

    void enqueue(int x);
    int dequeue();
    void print();
};

void queue::enqueue(int x)
{
    if (rear == size - 1)
    {
        cout << "queue is already full\n";
    }
    else
    {
        rear++;
        q[rear] = x;
    }
}

int queue::dequeue()
{
    int x = -1;
    if (front == rear)
    {
        cout << "queue is already empty\n";
    }
    else
    {
        x = q[front];
        front++;
    }
    return x;
}

void queue::print()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;
}

int main()
{
    queue j(5);
    j.enqueue(10);
    j.enqueue(20);
    j.enqueue(30);
    j.print();
    j.dequeue();
    j.print();
    return 0;
}