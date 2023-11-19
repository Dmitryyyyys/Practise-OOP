#include <iostream>
#include <ctime>

using std::cin; using std::cout; using std::endl;

struct Stack 
{
    int* data;
    int top;
};

void output(Stack& stack)
{
    for (int i = 0; i < stack.top; i++)
    {
        cout << stack.data[i] << '\t';
    }
}

void deleteNegative(Stack& stack) 
{
    int i = 0;

    while (i <= stack.top && stack.data[i] >= 0) 
    {
        i++;
    }

    if (i <= stack.top - 1) 
    {
        for (int j = i; j < stack.top - 1; j++) 
        {
            stack.data[j] = stack.data[j + 1];
        }
        stack.top--;
    }
}

int main() 
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");

    Stack stack;
    int n = NULL;
    cout << "Введите количество элементов в стеке: "; cin >> n;
    stack.data = new int[n];
    for (int i = 0; i < n; i++)
    {
        stack.data[i] = rand() % 10 - 5 + 1;
    }
    stack.top = n;

    output(stack);

    deleteNegative(stack);

    cout << endl << "Результат: ";
    output(stack);
    cout << endl;

    return 0;
}
