#include <iostream>
#include <stdlib.h>
#include <ctime>

using std::cin; using std::endl; using std::cout;

struct Node
{
    int data;
    Node* next;
};

void insert(Node*& head, int data)
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

double averagePositive(Node*& head)
{
    int sum = NULL;
    int count = 0;

    while (head != nullptr)
    {
        cout << head->data << '\t';
        if (head->data <= -10)
        {
            sum += head->data;
            count++;
        }
        head = head->next;
    }

    if (count == 0)
    {
        return 0;
    }
    else
    {
        return sum;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    Node* head = nullptr;
    int n = NULL;

    cout << "Введите количество элементов в списке: "; cin >> n;


    for (int i = 0; i < n; i++)
    {
        int temp = rand() % 10 - 15 + 1;
        insert(head, temp);
    }

    int avg = averagePositive(head);

    cout << endl << "сумма отрицательных элементов: " << avg << endl;

    return 0;
}