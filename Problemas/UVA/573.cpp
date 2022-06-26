#include <bits/stdc++.h>
using namespace std;
int main()
{
    float H,U,D,F;
    while(scanf("%f%f%f%f",&H,&U,&D,&F)==4 && H!=0)
    {
        int days=1;
        double res=0,aux=U,minus=F*U/100;
        while(res<H)
        {
            res+=aux;
            if((aux-minus)>0)
            aux-=minus;
            else aux=0;
            if(res>H) break;
            res-=D;
            if(res<0) break;
            days++;
        }
        if(res>0)
        cout<<"success on day "<<days<<endl;
        else
        cout<<"failure on day "<<days<<endl;
    }
    return 0;
}
