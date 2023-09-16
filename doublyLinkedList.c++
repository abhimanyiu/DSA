#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void print(node *head)
{
    node *temp = head;
    if (temp == NULL)
    {
        cout << "\n**EMPTY LIST**\n";
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

void insert(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
}

void ins_pos(node *head, int pos, int val)
{
    node *n = new node(val);
    node *temp = head;

    if (temp == NULL)
    {
        temp = n;
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            temp = temp->next;
        }
        n->prev = temp;
        n->next = temp->next;
        if (temp->next)
        {
            temp->next->prev = n;
        }
        temp->next = n;
    }
}

void del_pos(node *head, int pos)
{
    node *temp = head;
    if (temp == NULL)
    {
        cout << "\n**LIST IS EMPTY**\n";
    }
    else
    {
        for (int i = 1; i <= pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        if (temp->prev)
        {
            temp->next->prev = temp->prev;
        }
    }
}

int main()
{
    int n;
    node *head = NULL;

    while (true)
    {
        cout << endl
             << "1 create list \n2 print \n3 exit \n4 insert at position \n5 delete at position" << endl;
        cin >> n;

        if (n == 1)
        {
            int num;
            cout << "how many entries? ";
            cin >> num;

            for (int i = 0; i < num; i++)
            {
                int x;
                cout << "enter value ";
                cin >> x;
                insert(head, x);
            }
        }

        else if (n == 2)
        {
            print(head);
        }

        else if (n == 3)
        {
            exit(0);
        }

        else if (n == 4)
        {
            int val, pos;
            cout << "enter value ";
            cin >> val;
            cout << "enter pos ";
            cin >> pos;
            ins_pos(head, pos, val);
        }
        else if (n == 5)
        {
            int pos;
            cout << "enter position";
            cin >> pos;
            del_pos(head, pos);
        }
    }
    return 0;
}