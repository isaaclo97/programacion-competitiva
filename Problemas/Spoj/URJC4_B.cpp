#include<bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases; cin>>cases;
    while(cases--)
    {
        int n,m,flag=1; cin>>n>>m;
        string name;
        for(int i=0; i<m;i++)
        {
            bool posible=true;
            int m1,n1;
            cin>>name;
            cin>>m1;
            for(int j=1; j<n;j++)
            {
                cin>>n1;
                if(m1>=n1) posible=false;
                m1=n1;
            }
            if(flag==1&&posible) { cout<<name; flag=0;}
            else if(posible)cout<<" "<<name;
        }
        cout<<endl;
    }
    return 0;
}
