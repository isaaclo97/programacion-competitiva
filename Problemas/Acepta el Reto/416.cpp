#include <bits/stdc++.h>
using namespace std;
int main()
{
    int fechas,fechas1;
    string fechs;
    cin>>fechas;
    fechas1=fechas;
    while(fechas!=0)
    {
      string dia[fechas];
        while(fechas--)
        {
            string bueno="";
            cin>>fechs;
            for(int i=0;i<fechs.length()-5;i++)
                bueno+=fechs[i];
           dia[fechas]=bueno;

        }
        sort(dia,dia+fechas1);
        bool tiene=false;
        for(int o=0; o<fechas1-1&&!tiene;o++)
        {
            if(dia[o]==dia[o+1])
            {
                cout<<"SI\n";
                tiene=true;
            }
        }
        if(!tiene)
        cout<<"NO\n";
        tiene=false;
        cin>>fechas;
        fechas1=fechas;
    }
    return 0;
}
