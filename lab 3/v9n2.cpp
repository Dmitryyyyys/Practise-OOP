#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream in("in.txt"); // - открытие потока для чтения с файла in.txt в директории программы
    ofstream out("out.txt"); // - запись (по умолчанию перезапись)

    string line; // - временное хранилище для строк
    unsigned int amount = 0;
    bool exist = false;
    while (getline(in, line)) // - пока есть строки в файле
    {
        for (unsigned int i = 0; i < line.length(); i++)
            if (isdigit((unsigned char)line[i]))
                exist = true;

        if (!exist)
        {
            out << line << '\n';
            if (line[0] == 'A' || line[0] == 'a') // - влияет язык
                amount++;
        }
        else
            exist = false;
    }
    cout << "Количество строк, которые начинаються на 'A': " << amount;

    return 0;
}