#include <iostream>
#include <ctime>
#include <Windows.h>

using std::cin; using std::cout; using std::endl;

struct Stack
{
    std::string* data;
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

    while (i < stack.top)
    {
        if (stack.data[i].size() % 2 == 0)
        {
            std::string word = stack.data[i];
            std::string buf = word;
            for (int j = 0, reverse = 0; j < word.size(); j++)
            {
                if (j < word.size() / 2)
                {
                    word[j] = buf[(word.size() / 2) - j - 1];
                }
                else
                {
                    word[j] = buf[word.size() - reverse - 1];
                    reverse++;
                }
            }
            stack.data[i] = word;
            i++;
            word.clear();
            buf.clear();
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Stack stack;
    int n = NULL;
    cout << "Введите количество элементов в стеке: "; cin >> n;
    stack.data = new std::string[n];
    cout << "Вводите слова: ";
    for (int i = 0; i < n; i++)
    {
        std::string str;
        cin >> str;
        stack.data[i] = str;
    }
    stack.top = n;

    output(stack);

    deleteNegative(stack);

    cout << endl << "Результат: ";
    output(stack);
    cout << endl;

    return 0;
}