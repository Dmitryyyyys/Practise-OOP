#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

using std::cout; using std::cin; using std::endl;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::ifstream fileA("fileA.txt");
    std::ofstream fileB("fileB.txt");

    std::string line;
    std::vector<std::string> str;

    if (fileA.is_open())
    {
        while (std::getline(fileA, line))
        {
            if (line[0] >= '0' && line[0] <= '9')
            {
                str.push_back(line);
            }
        }
        fileA.close();
        for (auto a : str)
        {
            fileB << a << '\n';
        }
    }
    else
    {
        cout<<"file not open";
    }
}