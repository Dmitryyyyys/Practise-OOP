#include <iostream>
using namespace std;
int a[10], b[50], c;
void rec(int t)
{
    int i;
    if (t == c)
    {
        for (i = 0; i < c; i++)
            cout << b[i];
        cout << endl;
        return;
    }
    for (i = 0; i < 10; i++)
        if (a[i])
        {
            a[i]--;
            b[t] = i;
            rec(t + 1);
            a[i]++;
        }
}

int main()
{
    int n;
    cin >> n;
    while (n)
    {
        a[n % 10]++;
        n /= 10;
        c++;
    }
    rec(0);
    return 0;
}