#include <iostream>
using namespace std;
int main()
{
    string numero,numerocopy,original;
    int mayor,menor,numero1,total=0,casos,temp,temp1;
    cin>>casos;
    for(int i=0;i<casos;i++)
    {
        cin >> numero;
    //Ordenar
    for(int i=0; i<7;i++)
    {
        while(numero.length()!=4)
        {
            numero = "0"+numero;
        }
        numerocopy=numero;
        original=numero;
        if(numero[0]!=numero[1]||numero[0]!=numero[2]||numero[0]!=numero[3])
        {
        for(int i=0;i<4;i++)
            {
            for(int j=0;j<3;j++)
                {
                if(numero[j]>numero[j+1])
                     {
                 temp=numero[j];
                 numero[j]=numero[j+1];
                 numero[j+1]=temp;
                    }
                if(numerocopy[j]<numerocopy[j+1])
                     {
                 temp1=numerocopy[j];
                 numerocopy[j]=numerocopy[j+1];
                 numerocopy[j+1]=temp1;
                    }
                 }
             }
        menor = stoi(numero);
        mayor = stoi(numerocopy);

        numero1=mayor-menor;
        if(numero1==6174)
        {
            total= i+1;
            i=9;
        }
        if(original=="6174")
        {
            total=0;
            i=9;
        }
        numero=to_string(numero1);
        while(numero.length()!=4)
        {
            numero = "0"+numero;
        }
        }
        else
        {
            i=8;
            cout<<"8\n";
        }
    }
    if(numero[0]!=numero[1]||numero[0]!=numero[2]||numero[0]!=numero[3])
    {
    cout<<total<<"\n";
    }
    }
    return 0;
}
