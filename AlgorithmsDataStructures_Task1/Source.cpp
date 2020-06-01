#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

const int n = 4, d = 5, g = 10, X = 3;

void drukuj_tab(int* tab, string nazwa, int rozmiar)
{
    cout << endl;
    cout << "Dynamiczna tablica " << nazwa << " zawierajaca elementy:" << endl;
    for (int i = 0; i < rozmiar; i++)
    {
        if (i % X == 0)
        {
            cout << endl;
        }
        cout << setw(5) << tab[i] << '\t';
    }
    cout << endl;
}

int main()
{
    cout << "Tablice 'A' wypelniamy liczbami losowymi z przedzialu d-g" << endl;

    int A[n][n];

    srand(time(0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = d + rand() % (g + 1 - d);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << A[i][j] << '\t';
        cout << endl;
    }

    double suma = 0;
    double srednia = 0;
    for (int i = 0; i < n; i++)
        suma += A[i][i];
    srednia = suma / n;
    cout << "Srednia elementow glownej przekatnej = " << srednia << endl;

    int* B;
    int b = 0, r = 0, x;
    cout << endl;
    cout << "Podaj ile elementow moze byc wiekszych nad glowna przekatna: ";
    cin >> x;
    B = new int[x];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)

            if (A[i][j] > srednia)
            {
                //cout<<A[i][j]<<endl;
                B[r] = A[i][j];
                r++;
                b = r;
            }
    }
    drukuj_tab(B, "B", r);

    int* C;
    int c = 0, y;
    r = 0;
    cout << endl;
    cout << "Podaj ile elementow moze byc mniejszych pod glowna przekatna: ";
    cin >> y;
    C = new int[y];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i - 1; j++)

            if (A[i][j] < srednia)
            {
                //cout<<A[i][j]<<endl;
                C[r] = A[i][j];
                r++;
                c = r;
            }
    }
    drukuj_tab(C, "C", r);

    int* D;
    r = 0;
    D = new int[b + c];

    for (int i = 0; i < b; i++)
    {
        D[r] = B[i];
        r++;
    }
    for (int i = 0; i < c; i++)
    {
        D[r] = C[i];
        r++;
    }
    drukuj_tab(D, "D", r);


    delete[]B;
    delete[]C;
    delete[]D;


    return 0;
}
