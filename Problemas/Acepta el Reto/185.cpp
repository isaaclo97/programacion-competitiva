#include <bits/stdc++.h>
using namespace std;
int main()
{
    int numero=4;
    bool eliminar=false,esta=false;
    vector<string> lista_gusta,lista_nogusta,resultados;
    while(numero!=0)
    {
        cin>>numero;
        cin.ignore();
        if(numero!=0)
        {
            while(numero--)
            {
                string linea1="",lineaux="",palabra="";
                getline(cin,linea1);
                for(unsigned int i=4; i<linea1.length()-3;i++)
                    lineaux+=linea1[i];

                if(linea1[0]=='S')
                {
                    for(unsigned int p=0; p<lineaux.length();p++)
                    {
                        if(lineaux[p]==' ')
                        {
                            for(unsigned int k=0;k<lista_gusta.size();k++)
                                if(lista_gusta[k]==palabra) esta=true;
                         if(!esta)
                        lista_gusta.push_back(palabra);
                        p++; esta=false;
                        palabra="";
                        }
                        palabra+=lineaux[p];
                    }
                }
                else
                {
                    for(unsigned int p=0; p<lineaux.length();p++)
                    {
                        if(lineaux[p]==' ')
                        {
                            for(unsigned int k=0;k<lista_nogusta.size();k++)
                                if(lista_nogusta[k]==palabra) esta=true;
                         if(!esta)
                        lista_nogusta.push_back(palabra);
                        p++; esta=false;
                        palabra="";
                        }
                        palabra+=lineaux[p];
                    }
                }
            }
        for(unsigned int i=0; i<lista_nogusta.size();i++)
        {
            for(unsigned int p=0;p<lista_gusta.size();p++)
                if(lista_nogusta[i]==lista_gusta[p])
                {
                    eliminar=true;
                }
            if(!eliminar)
                resultados.push_back(lista_nogusta[i]);
            eliminar=false;
        }
        sort(resultados.begin(),resultados.end());
                for(unsigned int i=0; i<resultados.size();i++)
                {
                cout<<resultados[i];
                if(i+1!=resultados.size())
                    cout<<" ";
                }
                cout<<"\n";
        lista_nogusta.clear();
        lista_gusta.clear();
        resultados.clear();
        }
    }
    return 0;
}
