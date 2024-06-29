#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

long long hex_to_decimal(char p[]);
int todigit(char hex);

int main(void)
{
    int n = 50;
    printf("%p\n",&n);

    int * p = &n;

    // my code

    char pointer[20];
    snprintf(pointer,sizeof(pointer),"%p",p);
    long long bits = hex_to_decimal(pointer);
    printf("The n.th memory location of bytes in memory address = %lld\n",bits);
    int GB = bits / (2.0e10);
    printf("The approx KBth space taken is %d\n", GB);
    return 0;
}

long long hex_to_decimal(char p[])
{   
    int n = strlen(p);
    int sd = 0;
    long long counter = 1;
    long long value = 0;
    for(int i=n-1;i>1;i--)
    {
        sd = todigit(p[i]);
        value = value + sd * counter;
        counter = counter * 16;
    }
    return value;
}

int todigit(char hex)
{
    if(isdigit(hex))
    {
        return hex - '0';
    }
    else
    {
        hex = tolower(hex);
        return hex - 'a' + 10;
    }
}
