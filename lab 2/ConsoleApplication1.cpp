#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

struct Contact
{
    char fname[30];
    char sname[30];
    char address[150];
    char age[5];
    char phone[15];
};
struct birthday
{
   unsigned  month : 10;
   unsigned year : 10;
   unsigned day : 10;

};

const int EXT = 5;

void AddContact(Contact*&, int&, int&, Contact&);
void DeleteContact(Contact*& MainPtr, int&, int, int);
void ShowContact(Contact*, int);
void ShowAll(Contact*, int);
void FindContactFromNumber(Contact* arr, int count, char* Number);
void FindContactFromName(Contact* arr, int count, char* Name);
void ReadFile(Contact*& notebook, int& size, int& count, std::ifstream& ifile);
void WriteFile(Contact* arr, int count, std::ofstream& ofile);

int main()
{
    int size = 2;
    int count = 2;
    int ContactNumber;

    Contact* MainPtr = new Contact[size];
    MainPtr[0] = Contact{ "Ivan", "Ivanov", "Odessa", "34", "0482222222" };
    MainPtr[1] = Contact{ "Petr", "Petrov", "Odessa", "22", "0483333333" };

    Contact n_contact;

    char MenuChoise, Exit;
    //bool sorting;

    do
    {
        do
        {
            system("cls");
            cout << "******** NOTE BOOK ********" << endl << endl;
            cout << "(1) ADD NEW CONTACT" << endl << "(2) EDIT CONTACT" << endl << "(3) DELETE CONTACT" << endl
                << "(4) SHOW ALL CONTACTS" << endl << "(5) SHOW ONE CONTACT" << endl << "(6) FIND CONTACT" <<
                endl << "(7) SAVE FILE" << endl << "(8) LOAD FILE" << endl << "(9) EXIT" << endl << endl;
            MenuChoise = _getch();
            //std::cin.ignore();
        } while (MenuChoise < '1' && MenuChoise > '9');

        switch (MenuChoise)
        {
        case '1':
            cout << "Entering new contact..." << endl << endl;
            cout << "Enter first name: " << endl;
            std::cin.getline(n_contact.fname, 30);
            cout << "Enter second name: " << endl;
            std::cin.getline(n_contact.sname, 30);
            cout << "Enter year sdachi: " << endl;
            std::cin.getline(n_contact.address, 150);
            cout << "Enter day sdachi : " << endl;
            std::cin.getline(n_contact.age, 5);
            cout << "Enter month : " << endl;
            std::cin.getline(n_contact.phone, 15);

            AddContact(MainPtr, size, count, n_contact);
            break;
        case '3':
            cout << "Enter the number of contact for deleting: " << endl;
            cin >> ContactNumber;
            std::cin.ignore();
            if (ContactNumber > count || ContactNumber < 1)
            {
                cout << "Invalid number!" << endl;
                break;
            }
            DeleteContact(MainPtr, count, size, ContactNumber - 1);
            break;
        case '4':
            ShowAll(MainPtr, count);
            break;
        case '5':
            cout << "Enter the number of contact: " << endl;
            cin >> ContactNumber;
            std::cin.ignore();
            if (ContactNumber > count || ContactNumber < 1)
            {
                cout << "Invalid number!" << endl;
                break;
            }
            ShowContact(MainPtr, ContactNumber - 1);
            break;
        case '6':
            cout << "Enter the number of contact for searching: (0 - Name, 1 - Number, else - break)" << endl;
            cin >> ContactNumber;
            std::cin.ignore();
            if (ContactNumber == 0)
            {
                char Name[30];
                cout << "Enter name: " << endl;
                std::cin.getline(Name, 30);
                FindContactFromName(MainPtr, count, Name);
            }
            else if (ContactNumber == 1)
            {
                char Number[150];
                cout << "Enter number: " << endl;
                std::cin.getline(Number, 150);
                FindContactFromNumber(MainPtr, count, Number);
            }

            break;
        case '7':
        {

            cout << "Enter file name for writing: " << endl;
            std::cin.ignore();
            char fName[30];
            std::cin.getline(fName, 30);
            std::ofstream ofile(fName);
            if (!ofile)
                std::cout << "Error in openind file for writing.\n";
            else
                WriteFile(MainPtr, count, ofile);
        }
        break;
        case '8':
        {

            cout << "Enter file name for reading: " << endl;
            std::cin.ignore();
            char fName[30];
            std::cin.getline(fName, 30);
            std::ifstream ifile(fName);
            if (!ifile)
                std::cout << "Error in openind file for reading.\n";
            else
            {
                ReadFile(MainPtr, size, count, ifile);
            }
        }
        break;

        case '9':
            return 0;
        }

        cout << endl << "Do you want to make another operation? (1 - yes, 0 - no)" << endl;
        Exit = _getch();
    } while (Exit != '0');


    delete[]MainPtr;
    MainPtr = nullptr;
}

void AddContact(Contact*& notebook, int& size, int& count, Contact& NewContact)
{
    if (count + 1 >= size) //расширяем массив, если нет пустого места
    {
        size += EXT;
        Contact* temp = new Contact[size];
        for (int i = 0; i < count + 1; i++)
        {
            temp[i] = notebook[i];
        }

        delete[]notebook;
        notebook = temp;
    }
    notebook[count] = NewContact;  //копирование новой структуры

    cout << endl << "New cоntact has been added:" << endl;
    ShowContact(notebook, count);
    count++;
}

void DeleteContact(Contact*& notebook, int& count, int size, int number)
{
    Contact* temp = new Contact[size];
    for (int i = 0; i < number; i++)
    {
        temp[i] = notebook[i];
    }
    for (int i = number; i < size; i++)
    {
        temp[i] = notebook[i];
    }

    delete[]notebook;
    notebook = temp;
    count--;

    cout << endl << "Cоntact has been removed." << endl;

}

void FindContactFromNumber(Contact* arr, int count, char* Number)
{
    for (int i = 0; i < count; i++)
        if (strcmp(arr[i].phone, Number) == 0)
        {
            ShowContact(arr, i);
            return;
        }
    cout << endl << "Cоntact not found" << endl;
}

void FindContactFromName(Contact* arr, int count, char* Name)
{
    for (int i = 0; i < count; i++)
        if (strcmp(arr[i].fname, Name) == 0)
        {
            ShowContact(arr, i);
            return;
        }
    cout << endl << "Cоntact not found" << endl;
}

void ShowContact(Contact* ptr, int index)
{
    cout << endl << "Contact number: " << index + 1 << endl;
    cout << "First name: " << ptr[index].fname << endl;
    cout << "Second name: " << ptr[index].sname << endl;
    cout << "Year: " << ptr[index].address << endl;
    cout << "Day: " << ptr[index].age << endl;
    cout << "Month: " << ptr[index].phone << endl;
}

void ShowAll(Contact* arr, int count)
{
    for (int i = 0; i < count; i++)
        ShowContact(arr, i);
}
void ReadFile(Contact*& notebook, int& size, int& count, std::ifstream& ifile)
{
    char str[100];
    Contact NewContact;
    while (ifile.getline(str, 100))
    {
        sscanf(str, "%s %s %s %s %s", NewContact.fname, NewContact.sname, NewContact.address, NewContact.age, NewContact.phone);
        AddContact(notebook, size, count, NewContact);
    }

}
void WriteFile(Contact* arr, int count, std::ofstream& ofile)
{
    for (int i = 0; i < count; i++)
        ofile << arr[i].fname << " "
        << arr[i].sname << " "
        << arr[i].address << " "
        << arr[i].age << " "
        << arr[i].phone << endl;
}