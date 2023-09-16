#include <iostream>
using namespace std;

class stack
{
    int size;
    int top;
    int *arr;

public:
    stack(int size)
    {
        arr = new int[size];
        top = -1;
    }

    void push(int x)
    {
        if (top == size - 1)
        {
            cout << "stack is already full";
            return;
        }
        else
        {
            top++;
            arr[top] = x;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "stack is already empty";
            return;
        }
        else
        {
            top--;
        }
    }

    void print()
    {
        if (top == -1)
        {
            cout << "empty stack";
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{

    stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    s.pop();
    s.print();
    return 0;
}