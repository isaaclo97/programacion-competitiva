#include <iostream>
using namespace std;
int main()
{
    int casos,wifis;
    long int distancia1,aux=0;
    cin>>casos;
    for(int i=0;i<casos;i++)
    {
        cin >>distancia1>>wifis;
        int repetidores[wifis];
        long int distancia[wifis];
        for(int i=0;i<wifis;i++)
        {
            cin >>repetidores[i] >> distancia[i];
        }
        for(int i=0;i<wifis;i++)
        {
            if(aux>=repetidores[i]-distancia[i])
                if (aux<distancia[i]+repetidores[i])
                    aux=repetidores[i]+distancia[i];
        }
        if(aux>=distancia1)
            cout<<"SI\n";
        else
            cout<<"NO\n";
    aux=0;
    }
    return 0;
}
