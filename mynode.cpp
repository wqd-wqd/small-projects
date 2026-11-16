#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct _node
{
    int value;
    struct _node *next;
} Node;

typedef struct _list
{
    Node *head;
} List;

void print(List *plist);
void add(int num, List *plist);

int main()
{
    int num;
    List list;
    list.head = NULL;
    while (cin >> num && num != -1)
        add(num, &list);
    int isFound = 0;
    Node *p;
    Node *q;
    cin >> num;
    for (q = NULL, p = list.head; p; q = p, p = p->next)
    {
        if (p->value == num)
        {
            isFound = 1;
            if (q)
                q->next = p->next;
            else
                list.head = p->next;
            delete(p);
            break;
        }
    }
    if (isFound == 1)
        cout << "find\n";
    else
        cout << "no find\n";
    print(&list);
    for (p = list.head; p; p = q)
    {
        q = p->next;
        delete(p);
    }
    return 0;
}

void add(int num, List *plist)
{
    Node *p =new Node;
    Node *q;
    p->value = num;
    p->next = NULL;
    if (plist->head)
    {
        for (q = plist->head; q->next; q = q->next)
            ;
        q->next = p;
    }
    else
        plist->head = p;
}

void print(List *plist)
{
    Node *p;
    for (p = plist->head; p; p = p->next)
    {
        cout << p->value << "\t";
    }
    cout << "\n";
}