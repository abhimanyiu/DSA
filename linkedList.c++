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
};

void ins_last(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void ins_pos(node *head, int pos, int key)
{
    node *n = new node(key);
    int i = 0;
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL && i < pos - 1)
        {
            temp = temp->next;
            i += 1;
        }
        n->next = temp->next;
        temp->next = n;
    }
}

void del_end(node *head)
{
    node *temp = head;
    if (temp == NULL)
    {
        cout << "Link is empty";
        return;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
}

void del_pos(node *head, int pos)
{
    node *temp = head;
    int i = 0;
    if (temp->next == NULL)
    {
        cout << "link is empty";
        return;
    }
    else if (pos == 1)
    {
        temp = temp->next;
        return;
    }
    else
    {
        while (temp->next != NULL && i < pos - 2)
        {
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
    }
}

int main()
{
    int n;

    node *head = NULL;

    while (true)
    {
        cout << endl
             << "1 create list \n2 print \n3 exit \n4 insert at position \n5 delete at end \n6 delete at position"
             << endl;
        cin >> n;
        if (n == 1)
        {
            int num;
            cout << "how many entries?";
            cin >> n;

            for (int i = 0; i < n; i++)
            {
                int val;
                cout << "insert data here";
                cin >> val;
                ins_last(head, val);
            }
        }
        else if (n == 2)
        {
            print(head);
            continue;
        }
        else if (n == 3)
        {
            exit(0);
        }
        else if (n == 4)
        {
            int i, j;
            cout << "enter pos";
            cin >> i;
            cout << "enter value";
            cin >> j;
            ins_pos(head, i, j);
        }
        else if (n == 5)
        {
            del_end(head);
        }
        else if (n == 6)
        {
            int x;
            cout << "enter position";
            cin >> x;
            del_pos(head, x);
        }
    }
    return 0;
}