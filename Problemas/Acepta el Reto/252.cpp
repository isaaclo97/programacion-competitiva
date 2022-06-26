#include <iostream>
#include <string.h>

using namespace std;
int main()
{
    int v;
    bool valor=true;
    string cespacio;
    string sespacio;
    string cespacio1;
    do
    {
        getline(cin,cespacio);
        cespacio1=cespacio;
        for(int i=0;i<cespacio.length();i++)
        {
        if(cespacio[i]>64&&cespacio[i]<91)
            cespacio[i]+=32;
        }
        sespacio=cespacio;
        if(cespacio1!="XXX")
        {
                for (int i = 0, j = 0; i<cespacio.length(); i++,j++)
                {
                    if (cespacio[i]!=' ')
                        sespacio[j]=cespacio[i];
                    else
                        j--;
                    v=j;
                }
                v++;
                char reverso[v];
                for(int i=v-1,j=0; i>=0;i--,j++)
                    reverso[j]=sespacio[i];

            for(int i=0; i<v;i++)
            {
                if(reverso[i]!=sespacio[i])
                {
                    valor=false;
                }
            }
            if(valor)
                cout<<"SI\n";
            else
            {
                cout<<"NO\n";
                valor=true;
            }
        }
    }
    while(cespacio1!="XXX");

    return 0;
}
