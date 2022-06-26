#include <iostream>
using namespace std;
int main()
{
    int a,b,casos;
    int vector[5000];
    for(int i=0; i<5000; i++)
    {
        if(i==0)
        vector[i]= 1;
        if(i!=0)
            vector[i]=vector[i-1]+i;
    }

    cin>> casos;
    while(casos--)
    {
        cin>>a>>b;

    cout<<vector[b+a]+a<<"\n";
    }
    return 0;
}
