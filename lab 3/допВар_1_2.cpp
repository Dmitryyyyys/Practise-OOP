#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout; using std::cin; using std::endl;

int main()
{
    setlocale(LC_ALL, "ru");

    std::ifstream inputFile("f.txt");
    std::ofstream outputFile("g.txt");

    std::vector<int> numbers;
    std::string line;
    int individualNumber;

    int krat = NULL;

    if (inputFile.is_open() != 0)
    {
        while (std::getline(inputFile, line, '\n'))
        {
            for (int i = 0; i < line.size() - 2; i++)
            {
                if (line.at(i) == '-' && (line.at(i + 1) != ' ' && line.at(i + 2) != ' '))
                {
                    individualNumber = -((line[i + 1] - '0') * 10 + (line[i + 2] - '0'));
                    i += 2;
                    numbers.push_back(individualNumber);
                }
                else if (line.at(i) != ' ' && line.at(i + 1) != ' ')
                {
                    individualNumber = (line[i] - '0') * 10 + (line[i + 1] - '0');
                    numbers.push_back(individualNumber);
                }
            }
            inputFile.close();
        }
        cout << "Введите число, которому должны быть кратны числа файла f: " << endl; cin >> krat;
        for (auto num : numbers)
        {
            if (num % krat == 0)
            {
                outputFile << num << '\t';
            }
        }
    }
    else
    {
        cout << "file is not open";
    }
}
