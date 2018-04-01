#include <iostream>

using namespace std;

// n intre 0 si 10^4 = 10000 => int 
// ex n = 2380 -> 2138400
// ex n = 35 -> 35
void duplicare(int &n)
{
    int m = n, c = 1, cif;
    // vector in care tinem cifrele invers
    int v[50];
    
    while (m != 0)
    {
        cif = m % 10;
        
        // pentru cifre pare, adaugam 2 cifre, jumatatea si cifra
        if (cif % 2 == 0)
        {
            v[c++] = cif / 2;
            v[c++] = cif;
        } 
        else 
        {
            // altfel adaugam doar cifra
            v[c++] = cif;
        }
        
        m /= 10;
    }
    
    // a fost un c++ si la ultima iteratie
    c--;

    // reinitializam n
    n = 0;
    // parcurgere inversa si construire n
    // 2 -> 21 -> 213 -> 2138 -> 21384 -> 213840 -> 2138400
    for (int i = c; i >= 1; i--)
    {
        n = n * 10 + v[i];
    }
}

int main() {
    int n = 2380;
    duplicare(n);
    cout << "n = " << n << endl;
    n = 35;
    duplicare(n);
    cout << "n = " << n;

    return 0;
}
