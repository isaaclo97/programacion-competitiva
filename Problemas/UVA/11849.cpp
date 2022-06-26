#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
int n,m;
    while(scanf("%d %d",&n,&m)==2 && (n!=0 || m!=0))
    {
        int aux;
        map<int,int> M;
        for(int i=0; i<n+m;i++)  {cin>>aux; M[aux]++;}
        int sol = 0;
        for(auto m:M) if(m.second==2) sol++;
        cout<<sol<<endl;
    }
    return 0;
}
