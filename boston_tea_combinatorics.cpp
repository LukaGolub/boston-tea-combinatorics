#include <iostream>

using namespace std;

#define MAX 15000

long long komb(int a, int b, int c, int d, int e, int n)
{

    int limitA = (a == -1) ? n : a;
    int limitB = (b == -1) ? n : b;
    int limitC = (c == -1) ? n : c;
    int limitD = (d == -1) ? n : d;
    int limitE = (e == -1) ? n : e;

    int lim[5] = {limitA, limitB, limitC, limitD, limitE};

    long long poljeA[MAX + 1] = {0};
    long long poljeB[MAX + 1] = {0};
    long long poljeC[MAX + 1] = {0};
    long long poljeD[MAX + 1] = {0};
    long long poljeE[MAX + 1] = {0};

    long long poljeAxB[MAX + 1] = {0};
    long long poljeCxD[MAX + 1] = {0};
    long long poljeAxBxCxD[MAX + 1] = {0};
    long long poljeAxBxCxDxE[MAX + 1] = {0};

    for (int i = 0; i <= limitA; i++)
        poljeA[i] = 1;
    for (int i = 0; i <= limitB; i++)
        poljeB[i] = 1;
    for (int i = 0; i <= limitC; i++)
        poljeC[i] = 1;
    for (int i = 0; i <= limitD; i++)
        poljeD[i] = 1;
    for (int i = 0; i <= limitE; i++)
        poljeE[i] = 1;

    for (int i = 0; i <= limitA; i++) // odredi potencije pomnozenih zagrada (1+x+...+x^a)(1+x+...+x^b)
    {
        for (int j = 0; j <= limitB; j++)
        {
            if (i + j <= MAX)
                poljeAxB[i + j] += 1;
        }
    }

    for (int i = 0; i <= limitC; i++) //  CxD
    {
        for (int j = 0; j <= limitD; j++)
        {
            if (i + j <= MAX)
                poljeCxD[i + j] += 1;
        }
    }

    for (int i = 0; i <= MAX; i++) //   (AxB)x(CxD)
    {
        for (int j = 0; j <= MAX; j++)
        {
            if (i + j <= MAX)
                poljeAxBxCxD[i + j] += poljeAxB[i] * poljeCxD[j];
        }
    }

    for (int i = 0; i <= MAX; i++) //   [(AxB)x(CxD)]xE
    {
        for (int j = 0; j <= MAX; j++)
        {
            if (i + j <= MAX)
                poljeAxBxCxDxE[i + j] += poljeAxBxCxD[i] * poljeE[j];
        }
    }

    return poljeAxBxCxDxE[n];
}

int main(void)
{

    int a, b, c, d, e, n;

    cout << "Unesite broj vrecica caja Bohea (parametar a): ";
    cin >> a;
    cout << "Unesite broj vrecica caja Congou (parametar b): ";
    cin >> b;
    cout << "Unesite broj vrecica caja Souchong (parametar c): ";
    cin >> c;
    cout << "Unesite broj vrecica caja Singlo (parametar d): ";
    cin >> d;
    cout << "Unesite broj vrecica caja Hyson (parametar e): ";
    cin >> e;
    cout << "Unesite broj n: ";
    cin >> n;

    cout << "Gradjani Bostona mogu napraviti " << komb(a, b, c, d, e, n) << " razlicitih cajanki" << endl;

    return 0;

    // Probni primjer 1 6 -1 1 0 5
}
