#include <iostream>
#include <string.h>

using namespace std;

int main() {
    // n, m < 10^4 = 10000
    // unsigned int n, m; // [0, 65535]
    int n, m; // [-32767, 32767]
    
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;
    
    // folosim valorile citite pentru initializarea matricei
    int mat[n][m];
    
    // citire tablou initial
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
        }
    }
    // afisare rezultat
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    // salvam intr-o variabila valoarea conturului
    int c = mat[n][m];
    
    // completam pe prima si ultima coloana
    for (int i = 1; i <= n; i++)
    {
        mat[i][1] = mat[i][m] = c;
        // mat[i][m] = c;
    }
    
    // completam pe prima si ultima linie
    for (int i = 1; i <= m; i++)
    {
        mat[1][i] = mat[n][i] = c;
        // mat[n][i] = c;
    }
    
    // afisare rezultat
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    
    

    return 0;
}

