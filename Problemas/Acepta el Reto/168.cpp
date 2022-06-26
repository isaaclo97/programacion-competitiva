#include <iostream>
using namespace std;
int main()
{
    int casos,valor;
    bool esta=false;
    cin>>casos;
    while(casos!=0)
    {
        casos--;
        int valores[casos+1];
        int introducidos[casos];
        for(int p=0;p<casos;p++)
        {
            cin>>introducidos[p];
        }
        for(int i=0;i<casos+1;i++)
        {
            valores[i]=i+1;
        }
        for(int i=0; i<casos+1; i++)
        {
            for(int p=0;p<casos;p++)
            {
                valor=valores[i];
                if(valores[i]==introducidos[p])
                {
                    esta=true;
                    break;
                }
            }
            if(!esta)
                 break;

            esta=false;
        }
        cout<<valor<<"\n";
        cin>>casos;
    }
    return 0;
}
