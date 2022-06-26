#include <iostream>
using namespace std;
int main()
{
    int casos,numero,horas,minutos,valor,segundos;
    cin>>casos;

    for(int i=0;i<casos;i++)
    {
        horas=0;
        minutos=0;
        segundos=0;
        cin >> numero;
        if(numero>59)
        {
            while(numero>=3600)
            {
                numero-=3600;
                horas++;
            }
            minutos+=numero/60;
            valor=numero/60;
            numero-=valor*60;
            segundos+=numero;
        }
        else
        {
            segundos+=numero;
        }
        if(minutos<10&&segundos>9&&horas==0)
        {
        cout<< "00" <<":0"<< minutos<<":"<<segundos<<"\n" ;
        }
        else if(minutos<10&&segundos<10&&horas==0)
        {
        cout<< "00"<<":0"<< minutos<<":0"<<segundos<<"\n" ;
        }
        else if (minutos>9&&segundos<10&&horas==0)
        {
            cout<< "00"<<":"<< minutos<<":0"<<segundos<<"\n" ;
        }
        else if(minutos<10&&segundos>9&&horas<10)
        {
            cout<< "0"<<horas <<":0"<< minutos<<":"<<segundos<<"\n" ;
        }
        else if(minutos<10&&segundos>9&&horas>9)
        {
            cout<< ""<<horas <<":0"<< minutos<<":"<<segundos<<"\n" ;
        }
        else if(minutos<10&&segundos<10&&horas<10)
        {
            cout<< "0"<<horas<<":0"<< minutos<<":0"<<segundos<<"\n" ;
        }
        else if(minutos<10&&segundos<10&&horas>9)
        {
            cout<< ""<<horas<<":0"<< minutos<<":0"<<segundos<<"\n" ;
        }
        else if(minutos>9&&segundos<10&&horas<10)
        {
            cout<< "0"<<horas<<":"<< minutos<<":0"<<segundos<<"\n" ;
        }
        else if(minutos>9&&segundos<10&&horas>9)
        {
            cout<< ""<<horas<<":"<< minutos<<":0"<<segundos<<"\n" ;
        }
        else if(minutos>9&&segundos>9&&horas==0)
        {
            cout<< "00"<<":"<<minutos<<":"<<segundos<<"\n" ;
        }
        else if(minutos>9&&segundos>9&&horas<10)
        {
             cout<< "0"<<horas<<":"<<minutos<<":"<<segundos<<"\n" ;
        }
        else
        {
            cout<< ""<<horas<<":"<<minutos<<":"<<segundos<<"\n" ;
        }
    }
    return 0;
}
