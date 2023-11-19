#include"Header.h"
using namespace std;

int menu() {
    int UserChoose;
    cout << "Выберите функционал программы:" << endl
        << "\t1 <--- Добавить элемент в конец" << endl
        << "\t2 <--- Удалить элемент начала" << endl
        << "\t3 <--- Вывести очередь" << endl
        << "\t4 <--- Очистить очередь" << endl
        << "\t5 <--- Найти максимальный элемент" << endl
        << "\t6 <--- Найти минимальный элемент" << endl
        << "\t7 <--- Количество повторяющихся элементов очереди (d2)" << endl
        << "\t8 <--- Запись в файл" << endl
        << "\t9 <--- Чтение из файла" << endl
        << "\t10 <--- Очистить экран" << endl
        << "\t11 <--- Выход" << endl
        << "12 <--- Удаление трёх первых элементов и нахождение максимального элемента(d1)\n"
        << "13 <--- Кол-во элементов между максимальным и минимальным элементами очереди(d3)\n"
        << "Ввод: ";
    cin >> UserChoose;
    if (cin.fail()) {
        system("cls");
        cout << "\033[1;31m Попробуйте еще раз! \033[0m" << endl;
        cin.clear();
        cin.ignore(INT16_MAX, '\n');
        system("cls");
        menu();
    }
    return UserChoose;
}

int main() {
    setlocale(LC_ALL, "rus");

    Queue list;

    do {
        switch (menu()) {
        case 1:
        {
            system("cls");
            int input;
            cout << "Введите число: "; cin >> input;
            list.push(input);
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            list.pop_front();
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            list.ShowInfo();
            system("pause");
            break;
        }
        case 4:
        {
            system("cls");
            list.clearList();
            system("pause");
            break;
        }
        case 5:
        {
            system("cls");
            list.FindMax();
            system("pause");
            break;
        }
        case 6:
        {
            system("cls");
            list.FindMin();
            system("pause");
            break;
        }
        case 7:
        {
            system("cls");
            cout << "Количество повторяющихся элементов стека: " << list.SearchEqual() << endl;
            system("pause");
            break;
        }
        case 8:
        {
            system("cls");
            string filename;
            cout << "Введите название файла: "; cin >> filename;
            list.WriteFile(filename);
            system("pause");
            break;
        }
        case 9:
        {
            system("cls");
            string filename;
            cout << "Введите название файла: "; cin >> filename;
            list.ReadFile(filename);
            system("pause");
            break;
        }
        case 10:
        {
            system("cls");
            break;
        }
        case 11:
        {
            system("cls");
            cout << "\033[1;31m Спасибо! \033[0m";
            return 0;
            break;
        }
        case 12:
            system("cls");
            list.dop1();
            system("pause");
            break;
        case 13:
            system("cls");
            list.dop2();
            system("pause");
            break;
        default: {
            break;
        }
        }

    } while (true);

    return 0;
}