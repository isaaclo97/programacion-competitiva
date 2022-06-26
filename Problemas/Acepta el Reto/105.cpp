#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i=0,valor1=0,valor2=0;
    double media=0,domingo;
    vector<string> dia= {"MARTES","MIERCOLES","JUEVES","VIERNES","SABADO","DOMINGO"};
    double numero=0,maxi=INT_MIN,mini=INT_MAX;
    while(scanf("%lf",&numero)!=EOF)
    {
        if(numero==-1)
            break;
        if(maxi<numero)
        {
            maxi=numero;
            valor1=i;
        }
        if(mini>numero)
        {
            mini=numero;
            valor2=i;
        }
        if(i==5)
            domingo=numero;

             media+=numero;
        i++;
        if(i==6)
        {
            i=0;
            media/=6;
            cout << dia[valor1]<<" "<<dia[valor2];
            if(media==domingo)
                cout<<" EMPATE\n";
            else if(media>domingo)
                cout<<" NO\n";
            else
                cout<<" SI\n";

            media=0; maxi=INT_MIN,mini=INT_MAX;
        }
    }
    return 0;
}
