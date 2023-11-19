# include <iostream>    
#include <Windows.h>
#include <cstring>
#include <algorithm>
# define str_len 30                               
# define size 30  
using namespace std;

int choice;

struct sanatori
{
    char name[str_len];
    char profil[15];
    int count;
    char place[10];
};

struct sanatori  massivsanatori[size];
struct sanatori  bad;
int current_size = 0;

void enter_new()
{
    cout << "Ввод информации" << endl;
    if (current_size < size)
    {
        cout << "Строка номер ";
        cout << current_size + 1;
        cout << endl << " \n Название санатория: ";
        cin >> massivsanatori[current_size].name;
        cout << "\n Профиль: ";
        cin >> massivsanatori[current_size].profil;
        cout << "\n Количество путевок: ";
        cin >> massivsanatori[current_size].count;
        cout << "\n Место нахождения: ";
        cin >> massivsanatori[current_size].place;
        current_size++;
        cout << endl;
    }
    else
        cout << "Введено максимальное кол–во строк";
    //здесь нужно отсортировать по профелям и названием санатория, у меня только получилось отсортировать по профелям, т.е. по одному полю
    //ниже в комментариях сортировка по профелю
            //sanatori swap;
            //int j;
            //for (int i = 0; i < current_size; i++) {
            //  for (int j = i + 1; j < current_size; j++)
            //      if (strcmp(massivsanatori[i].profil, massivsanatori[j].profil) > 0)
            //      {
            //          swap = massivsanatori[i];
            //          massivsanatori[i] = massivsanatori[j];
            //          massivsanatori[j] = swap;
            //      }
            //}
}

void del()
{
    int d;
    cout << "\nНомер строки, которую надо удалить (для удаления всех строк нажать 99)" << endl;
    cin >> d;
    if (d != 99)
    {
        for (int de1 = (d - 1); de1 < current_size; de1++)
            massivsanatori[de1] = massivsanatori[de1 + 1];
        current_size = current_size - 1;
    }
    if (d == 99)
        for (int i = 0; i < size; i++)
            massivsanatori[i] = bad;
    exit;
}

void change()
{
    int n, per;
    cout << "\nВведите номер строки" << endl;     cin >> n;
    do
    {
        cout << "Введите: " << endl;
        cout << "1–для изменения названия санотория" << endl;
        cout << "2–для изменения профиля" << endl;
        cout << "3–для изменения кол-ва путевок" << endl;
        cout << "4–для изменения места нахождения" << endl;
        cout << "5–конец\n";
        cin >> per;
        switch (per)
        {
        case 1: cout << "Новое название:";
            cin >> massivsanatori[n - 1].name;   break;
        case 2: cout << "Новый профиль:";
            cin >> massivsanatori[n - 1].profil; break;
        case 3: cout << "Новое ко-во путевок: ";
            cin >> massivsanatori[n - 1].count; break;
        case 4: cout << "Новое место нахождение :";
            cin >> massivsanatori[n - 1].place; break;
        }
    } while (per != 5);
    exit;
}
void out()
{
    int sw, n;
    cout << "1–вывод 1 строки" << endl;
    cout << "2–вывод всех строк" << endl;
    cin >> sw;
    if (sw == 1)
    {
        cout << "Номер выводимой строки " << endl;
        cin >> n;
        cout << endl;
        cout << "Название санатория: ";
        cout << massivsanatori[n - 1].name << endl;
        cout << "Профиль: ";
        cout << massivsanatori[n - 1].profil << endl;
        cout << "Количество путевок :";
        cout << massivsanatori[n - 1].count << endl;
        cout << "место нахождения: ";
        cout << massivsanatori[n - 1].place << endl;
    }
    if (sw == 2)
    {
        for (int i = 0; i < current_size; i++)
        {
            cout << "Название санатория: ";
            cout << massivsanatori[i].name << '\t';
            cout << "Профиль: ";
            cout << massivsanatori[i].profil << '\t';
            cout << "Количество путевок: ";
            cout << massivsanatori[i].count << endl;
            cout << "место нахождения: ";
            cout << massivsanatori[i].place << endl;
        }
    }
    exit;
}
void  profil_out()
{
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "|" << " Профиль           " << "|" << " Санаторий   " << "|" << " Кол-во путевок" << "|" << " Место нахождения" << "|" << endl;
    for (int i = 0; i < current_size; i++)
    {
        cout << "----------------------------------------------------------------------------------------------" << endl;
        cout << massivsanatori[i].profil << massivsanatori[i].name << massivsanatori[i].count << massivsanatori[i].place << endl;
    }
    cout << "----------------------------------------------------------------------------------------------" << endl;
}
void find()
{
    string b;
    string profil2;
    cout << "По какому профилю вы хотите получить информацию?" << endl;
    cin >> profil2;

    for (int i = 0; i < current_size; i++)
    {
        if (massivsanatori[i].profil == profil2)
        {
            cout << "Название санатория:" << massivsanatori[i].name << "\t" << "Кол-во путевок:" << massivsanatori[i].count << "\t" << "Место нахождение:" << massivsanatori[i].place << "\t" << endl;
        }
    }
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "Russian");
    cout << "Данных нет" << endl;
    do
    {
        cout << "Введите:" << endl;
        cout << "1–для удаления записи" << endl;
        cout << "2–для ввода новой записи" << endl;
        cout << "3–для изменения записи" << endl;
        cout << "4–для вывода записи(ей)" << endl;
        cout << "5–таблица" << endl;
        cout << "6–для поиска информации" << endl;
        cout << "7–для выхода" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:  del(); break;
        case 2:  enter_new();  break;
        case 3:  change();  break;
        case 4:  out(); break;
        case 5:  profil_out(); break;
        case 6:  find(); break;

        }
    } while (choice != 7);
}