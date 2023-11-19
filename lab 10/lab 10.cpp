#include<iostream>
#include<math.h>
using namespace std;




//13 вариант
unsigned int dnx(unsigned int n, unsigned int x) {
    unsigned int count = 1;
    if (n % x == 0 && x > 1) {
        count = dnx(n, x - 1) + 1;
    }
    else if (n % x != 0 && x > 1) {
        count = dnx(n, x - 1);
    }
    return count;

}

int main() {
    setlocale(LC_ALL, "rus");
    unsigned int input;
    cout << "Введите положительное число: "; cin >> input;
    cout << "Итог работы программы: " << dnx(input, 100) << endl;
    return 0;
}


//1 Вариант

//unsigned long long fact(int N)
//{
//  if (N == 0 || N == 1)
//    return 1;
//  else
//    return N * fact(N - 1);
//}
//
//int main()
//{
//  int N;
//  setlocale(0, "");
//  cout << "Введите число для вычисления факториала: ";
//  cin >> N;
//  cout << "Факториал для числа " << N << " = " << fact(N) << endl << endl;
//  return 0;
//}

//6 Вариант

//unsigned long long Ack(unsigned int n, unsigned int m)
//{
//  if (n == 0)
//    return m + 1;
//  else if ((n != 0) && (m == 0))
//    return Ack(n - 1, 1);
//  else
//    return Ack(n - 1, Ack(n, m - 1));
//}
//
//int main() {
//  setlocale(LC_ALL, "rus");
//
//  int first;
//  int second;
//
//  cout << "Введите первое число: " << endl; cin >> first;
//  cout << "Введите второе число: " << endl; cin >> second;
//
//  system("pause");
//  system("cls");
//
//  cout << "Итог работы рекурсии " << Ack(first, second);
//
//  return 0;
//}

//16 Вариант

//unsigned long long mult(unsigned int n, unsigned int m)
//{
//  if (n == 0) {
//    return 1;
//  }
//  else if (n > m) {
//    return -1;
//  }
//  else {
//    return 2 * mult(n - 1, m);
//  }
//}
//
//int main() {
//  setlocale(LC_ALL, "rus");
//
//  int first;
//  int second;
//
//  cout << "Введите первое число: " << endl; cin >> first;
//  cout << "Введите второе число: " << endl; cin >> second;
//
//  system("pause");
//  system("cls");
//
//  cout << "Итог работы рекурсии " << mult(first, second);
//
//  return 0;
//}