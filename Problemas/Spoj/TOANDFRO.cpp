#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
        string te,resul;
        cin>>te;
        int c= n;
        int m=0,l=0,j=1;
        while(c!=m)
        {
            l=m;
            for(int i=0;i<te.length()/n;i++)
            {
                resul+=te[l];
                if(i%2==0)
                l+=(n*2)-j;
                else
                   l+=j;
            }
            m++;
            j+=2;
        }
        cout<<resul<<endl;
        cin>>n;
    }
    return 0;
} 
