#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool fal;
    string FILL = "000000000";
    string linea;
    string numero1,numero2,numero3,sol;
    while(getline(cin,linea))
    {
    numero1=""; numero2=""; numero3="";
    int co=0;
    sol="";
    for(int i=0;i<linea.length();i++)
    {
        if(linea[i]==' ')
        {
            co++;
            continue;
        }
        if(co==0)
            numero1+=linea[i];
        else if(co==1)
            numero2+=linea[i];
        else
            numero3+=linea[i];
    }
    fal=true;
    int i= numero1.length();
    if(numero1.length()<numero2.length())
        i=numero2.length();
    if(numero3.length()>i)
        i=numero3.length();
    numero1= FILL.substr(numero1.length())+numero1;
    numero2= FILL.substr(numero2.length())+numero2;
    numero3= FILL.substr(numero3.length())+numero3;

    for(int k=9-i;k<9;k++)
    {
            if(numero1[k]==numero2[k]&&numero1[k]!=numero3[k])
            {
                sol+=numero1[k];
            }

            else if(numero1[k]==numero3[k]&&numero1[k]!=numero2[k])
            {
                sol+=numero1[k];
            }

            else if(numero2[k]==numero3[k])
            {
                sol+=numero2[k];
            }
            else{
              fal=false;
            break;
            }
    }
    if(fal)
    {
        istringstream a1(sol);
        int a;
        a1>>a;
        printf("%d\n",a);
    }
    else
        printf("RUIDO COSMICO\n");

    }
    return 0;
}
