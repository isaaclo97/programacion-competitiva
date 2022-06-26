#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> aux;
void isLucky(int numero)
{
    bool first = true;
    unsigned int contador = 3;
    while(a.size()>=contador || first)
    {
        if(first)
        {
            for(int i=2; i<=numero;i+=2) a.push_back(i);
            first=false;
        }
        else
        {
            for(unsigned int i=0; i<a.size();i++)
            {
                if(i%contador==0) continue;
                aux.push_back(a[i]);
            }
            a.clear();
            for(unsigned int i=0; i<aux.size();i++) a.push_back(aux[i]);
            aux.clear();
            contador++;
        }

    }
}
int main()
{
    int numero;
    while(scanf("%d",&numero)==1&&numero!=0)
    {
        isLucky(numero);
        cout<<numero<<": ";
        for(int i=a.size()-1;i>=0;i--)
        {
            if(i!=0) cout <<a[i]<<" ";
            else  cout<<a[i]<<"\n";
        }
      a.clear();
    }
    return 0;
}
