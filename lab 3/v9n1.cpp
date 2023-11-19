#include  <stdio.h>

int main(void)
{
    char buf[200];
    int digits[10] = { 0 };

    fgets(buf, 200, stdin);

    for (int i = 0; buf[i]; ++i)
    {
        if (digits[buf[i] - '0'] == 0)
        {
            printf("%c", buf[i]);
            digits[buf[i] - '0'] = 1;
        }
    }

    return 0;
}