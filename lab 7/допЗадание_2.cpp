#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <Windows.h>
#include <vector>

using std::cin; using std::cout; using std::endl;

struct Stack
{
    int* data;
    int top;

    friend void output(Stack& stack);
};

void output(Stack& stack)
{
    for (int i = 0; i < stack.top; i++)
    {
        cout << stack.data[i] << '\t';
    }
}

void find_min(Stack& stack)
{
    int i = 0;

    int min = stack.data[0];
    for (; i < stack.top; i++)
    {
        if (min > stack.data[i])
        {
            min = stack.data[i];
        }
    }
    cout << min << endl << "Находится под номером: " << i;
}

int main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Stack stack;

    std::ifstream inputFile("fileA.txt");
    std::ofstream outputFile("fileB.txt");

    std::string line;
    std::vector<int> countiens;
    int count = NULL;

    while (std::getline(inputFile, line, '\n'))
    {
        countiens.push_back(line.size());
        count++;
    }
    stack.top = count;
    stack.data = new int[stack.top];

    for (int i = 0; i < count; i++)
    {
        stack.data[i] = countiens[i];
    }
    countiens.clear();
    cout << endl << "Результат: ";
    output(stack);

    cout << endl << "Размер самой маленькой строки: ";
    find_min(stack);

    return 0;
}