#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

int main()
{
    int casos=0;
    cin >> casos;
    char palabras[casos][40];

    for(int i=0; i<casos; i++)
    {
       cin >> palabras[i];
       if(palabras[i][0]>64 && palabras[i][0]<91)
       {
       palabras[i][0]=tolower(palabras[i][0]);
       palabras[i][strlen(palabras[i])-1]=toupper(palabras[i][strlen(palabras[i])-1]);
       }
       for (int j=strlen(palabras[i])-1; j>=0;j--)
       {
           cout << palabras[i][j];
       }
       cout << "\n";
    }
    return 0;
}
