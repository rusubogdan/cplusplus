#include <iostream>
#include <string.h>

using namespace std;

int main() {
    int n, nr_voc_min = 256; // 256 ar fi un cuvant maxim ce poate fi citit
    char prop[255];
    char rezultat[255];
    char *p;
    char voc[] = "aeiou"; // se va aloca automat memorie pentru voc
    
    cout << "n = ";  cin >> n;
    // in consola, atunci cand am apasat Enter pentru a finaliza introducerea
    // lui n am introdus in stream-ul de intrare al programului caracterul newline(\n)
    // de aceea, trebuie sa scapam de acesta pentru o noua citire, altfel primul 
    // sir de caractere citit cu getline va fi chiar '\n', ceea ca nu vrem
    // metoda get consuma caracterul \n iar rezultatul intors este ignorat
    // http://www.cplusplus.com/forum/beginner/92979/
    cin.get(); // sau cin.ignore();
    
    for (int i = 0; i < n; i++)
    {
        // citeste in prop linia de la tastatura
        cin.getline(prop, 255);
        cout << "prop: = " << prop << endl;
        
        // facem o copie
        char copie[256];
        strcpy(copie, prop);
        
        // nr de voc pentru toate cuvintele din propozitie
        int nr_voc = 0;
        // sparge in cuvinte (tokens) propozitia 
        p = strtok(prop, " ");

        while (p != NULL)
        {
            char *pch;
            // pozitionez un pointer la prima vocala din cuvant (token)
            pch = strpbrk(p, voc);
            
            while (pch != NULL)
            {
               nr_voc ++;
               pch = strpbrk(pch + 1, voc);
            }
            
            // p va pointa la urmatorul token (cuvant)
            p = strtok (NULL, " ");
        }
        
        if (nr_voc < nr_voc_min) 
        {
            nr_voc_min = nr_voc;
            strcpy(rezultat, copie); 
        }
        
        nr_voc = 0;
    }
    
    cout << endl << "Prop cu nr minim de vocale: " << rezultat << endl;
    
    return 0;
}

