#include <iostream>
#include <clocale>
#include <ctime>
#include <Windows.h>

using namespace std;

union Utypes
{
    char Family;
    char Name;
    char Fathername;
    char Sex;
    int Date;
    void Show();
    void Input();
} mun;



struct gorozhanin //Структура Студент
{
    char Family[35]; //Фамилия
    char Name[35]; //Имя
    char Fathername[35]; // Отчество
    char Sex[20]; //Пол
    int Date; //Дата рождения
    void Show(); //Функция будет отображать данные
    void Input(); //Функция ввода данных в структуру
};


int main()
{
    const int size = 7;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a;
    int b;
    int Date2;
    string Sex2;
    cout << "Vvedite kol-vo gorogan - ";
    cin >> a;
    gorozhanin massivgorozhan[size];

    for (int i = 0; i < a; i++)
    {
        cout << "Vvedite familiu [" << i + 1 << "] goraganina - ";
        cin >> massivgorozhan[i].Family;

        cout << endl;

        cout << "\n" << "Vvedite ima [" << i + 1 << "] goraganina - ";
        cin >> massivgorozhan[i].Name;

        cout << "\n" << "Vvedite otchestvo [" << i + 1 << "] goraganina - ";
        cin >> massivgorozhan[i].Fathername;

        cout << "\n" << "Vvedite pol [" << i + 1 << "] goraganina - ";
        cin >> massivgorozhan[i].Sex;

        cout << "\n" << "Vvedite god rogdenia [" << i + 1 << "] goraganina - ";
        cin >> massivgorozhan[i].Date;
    }

    cout << "Kakie dannie vi mogete vvesti dla podbora goragan?" << endl;
    cout << "1 - pol \n" << "2 - god rogdenia" << endl;
    cin >> b;
    if (b >= 3)
    {
        cout << "vi vveli chislo bolshe 2!" << endl;
        return 0;
    }
    if (b == 1)
    {
        cout << "Vvedite nugnii pol - ";
        cin >> Sex2;
        string man = "men";
        string woman = "women";
        if (Sex2 == man)
        {
            for (int i = 0; i < a; i++)
            {
                if (massivgorozhan[i].Sex == man)
                {
                    cout << massivgorozhan[i].Family << endl;
                }
            }
        }

        if (Sex2 == woman)
        {
            for (int i = 0; i < a; i++)
            {
                if (massivgorozhan[i].Sex == woman)
                {
                    cout << massivgorozhan[i].Family << endl;
                }
            }
        }
        else cout << "Vvedennui vami pol neizvesten" << endl;
    }
    if (b == 2)
    {
        cout << "Vvedite god rogdenia -";
        cin >> Date2;
        if (Date2 > 2022)
        {
            cout << "vvedenoe vami chislo bolhe tekuchego goda" << endl;
        }
        else
        {
            for (int i = 0; i < a; i++)
            {
                if (massivgorozhan[i].Date == Date2)
                {
                    cout << massivgorozhan[i].Family;
                }
            }
        }
    }
    cout << "Razmer obidinenia coctovlaet " << sizeof(Utypes) << " bait.";
    return 0;
}