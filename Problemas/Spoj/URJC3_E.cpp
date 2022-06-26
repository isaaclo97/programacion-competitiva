//Problema E
//Bar Progress

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        long double a,b;
        cin>>a>>b;
        if(a==b)
            cout<<"||||||||||\n";
        else if(a==0)
            cout<<"----------\n";
        else
        {
            long double k = (a/b)*10;
            int a = (int) k;
            if(k>a)
                a++;
            for(int i=1; i<=10;i++)
            {
                if(a>=i)
                    cout<<"|";
                else
                    cout<<"-";
            }
            cout<<endl;
        }
    }
    return 0;

}
