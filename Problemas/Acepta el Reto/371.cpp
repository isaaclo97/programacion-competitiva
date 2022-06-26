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
    cout << (3*numero*(numero+1))/2<<"\n";
    }
    }
    while(numero!=0);
    return 0;
}
