#include <bits/stdc++.h>
using namespace std;
int main()
{
    int casos,num,valor,salb,sala,valor2;
    cin>>casos;
            while(casos--)
            {
                salb=0; sala=0;
                cin>>num;
                cin>>valor;
                for(int i=0; i<num-1;i++)
                {
                    cin>>valor2;
                    if(valor<valor2)
                        sala++;
                    if(valor>valor2)
                        salb++;
                            valor=valor2;
                }
                cout<< sala << " " <<salb<<"\n";
            }
    return 0;
}
