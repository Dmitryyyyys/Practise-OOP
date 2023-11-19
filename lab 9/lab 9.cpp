#include<iostream>
using namespace std;
struct A
{
    int value;
};
struct List
{
    A a;
    List* next;
    List* prev;
};

void Create(List** ptr)
{
    *ptr = new List;
    A a[9] = { 10,20,30,40,50,60,70,80,90 };
    (*ptr)->a = a[0];
    (*ptr)->next = NULL;
    List* end = *ptr;
    for (int i(1); i < 9; i++)
    {
        end->next = new List;
        end = end->next;
        end->a = a[i];
        end->next = NULL;

    }
}
void Print(List* ptr)
{
    List* print = ptr;
    while (print)
    {
        cout << print->a.value << "->";
        print = print->next;
    }
    cout << "NULL" << endl;

}
void Del(List** begin, int val)
{
    List* t = *begin;
    if (t->a.value == val)
    {
        *begin = t->next;
        delete t;
        return;
    }
    List* t1 = t->next;
    while (t1)
    {
        if (t1->a.value == val)
        {
            t->next = t1->next;
            return;
        }
        t = t->next;
        t1 = t1->next;

    }
    cout << "NO match" << endl;
    return;


}
int main() {
    List* begin = NULL;
    Create(&begin);
    Print(begin);
    int val = 0;
    cin >> val;
    Del(&begin, val);
    Print(begin);
    return 0;
}