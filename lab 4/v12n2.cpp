#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <string>
#include <algorithm>

using std::cin; using std::cout; using std::endl; using std::min_element;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream inputFile("FileA.txt");
    std::ofstream outputFile("FileA.txt");

    std::vector<char> str_vector;
    std::string line;

    char str[100];

    gets_s(str);
    outputFile << str << endl;

    while (std::getline(inputFile, line, '\n'))
    {
        for (int i = 0; i < line.size(); i++)
        {
            str_vector.push_back(line[i]);
        }
    }
    inputFile.close();
    for (auto a : str_vector)
    {
        if (a % 2 != 0)
        {
            cout << a << '\t';
        }
    }
}