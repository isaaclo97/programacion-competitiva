#include <iostream>
using namespace std;

int main()
{
    int numero=-1;
    do
    {
    cin >> numero;
    if(numero!=0)
    {
    for(int i=0; i< numero; i++)
        cout<< "1";
    cout << "\n";
    }
    }
    while(numero!=0);
    return 0;
}
