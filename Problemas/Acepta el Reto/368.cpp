#include <iostream>
using namespace std;

int main()
{
    int huevo=0;
    int capacidad=0;
    int constante = 10;
    int acumulado=0;
    do
    {
    cin >> huevo;
    cin >> capacidad;
    if(huevo!=0&&capacidad!=0)
    {
    if(huevo>capacidad)
    {
    while (huevo>capacidad)
    {
        huevo-=capacidad;
        acumulado+=constante;
    }
    cout << acumulado + 10<< "\n";
        acumulado=0;
       }
    else
        cout<< constante << "\n";
    }
    }
    while(huevo!=0&&capacidad!=0);
    return 0;
}
