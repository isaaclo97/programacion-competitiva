#include <iostream>
using namespace std;

int main()
{
    int casos=0;
    long long int numero1,resultado;
    cin >> casos;
    for(int i=0; i<casos; i++)
    {
        cin >> numero1;
        numero1--;
        resultado= 6*numero1*numero1+2;
        cout << resultado<<"\n";
   }
    return 0;
}
