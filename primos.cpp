#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <math.h>
#define N 1000
using namespace std;
char* dec2bin2(int n, int inic);
char* dec2bin(int n);
int bin2dec(char *pal);
char* inverte(char* num);
int ehPrimo (int n);
int main ()
{
	char *bi =(char*) malloc(sizeof(char)*N);
	int i=2,k=1;
    puts("_____________________________________________________________________________________________________________________________\n");
    printf("k %-14ci %-14ci-k %-12cbin(i) %-9cinvdecimal(i) %-5cinvbin(i) %-6cbin(i-k) %-7cinvbin(i-k)\n", ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    puts("_____________________________________________________________________________________________________________________________\n");
    for(i=2; i<N; i++)
    {
        if(ehPrimo(i))
        {
            printf("%-15d %-15d %-15d %-15s %-18d %-15s %-15s %-15s\n", k++, i, i-k,dec2bin(i), bin2dec(dec2bin(i)), inverte((dec2bin(i))), dec2bin(i-k), inverte((dec2bin(i-k) )) );

            //printf("\n%-15d %-15.f\n\n", i, sq
        }

    }
	return 0;
}
char* dec2bin(int n)
{
    dec2bin2(n,0);
}

char* dec2bin2(int n, int inic)
{
    char static *num = (char*) malloc((sizeof(char)*N)) ;
    if (n/2>0)
    {
        num[inic++] = n%2 + '0';
        dec2bin2 (n/2, inic);
    }
    else
    {
        num[inic++] = n%2 + '0';
        num[inic] = '\0';
        return inverte(num);
    }
}
char* inverte(char* num)
{
    int k=0;
    char *p = (char*) malloc(sizeof(char)*strlen(num)+1);
    for(int i=strlen(num)-1; i>=0; i--)
        p[k++] = num[i];
    p[k] = '\0';
    return p;
}
int bin2dec(char *pal)
{
    int total=0;
    for(int i=0; i<strlen(pal); i++)
        total+=pow(2,i) *(pal[i]-'0');
    return total;
}


int ehPrimo (int n)
{
    for(int i=2; i<=sqrt(n); i++)
        if(n%i==0)
            return 0;
    return 1;
}
