#include <iostream>
#include <stdlib.h>
#include <ctime>

using std::cin; using std::endl; using std::cout;

struct Node
{
    char data;
    Node* next;
};

void insert(Node*& head, char data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void output(Node*& head)
{
    while (head != nullptr)
    {
        head = head->next;
    }
}

void averagePositive(Node*& head, char& my_symbl)
{
    int sum = NULL;
    int count = 0;

    while (head != nullptr)
    {
        if (head->next->data == my_symbl)
        {
            cout << endl << head->data << '\t' << head->next->data << '\t' << head->next->next->data;
            break;
        }
        head = head->next;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    Node* head = nullptr;
    int n = NULL;

    char symbl;
    cout << endl << "Введите символ, который надо найти: "; cin >> symbl;

    cout << "Введите количество элементов в списке: "; cin >> n;

    cout << endl << "Вводите символы: ";
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        insert(head, temp);
    }

    averagePositive(head, symbl);

    return 0;
}