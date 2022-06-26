#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("C:/Users/Isaac/Documents/QT/Entregar/in.txt","r",stdin);
    int n; scanf("%d",&n);
    map<string,int> M;
    map<string,int> Maux;
    for(int i=0; i<n;i++)
    {
        string line; cin>>line;
        M[line]++;
    }
    for(int i=0; i<n;i++)
    {
        string line; cin>>line;
        Maux[line]++;
    }
    long long int res = 0;
    for(auto m:M)
    {
        if(Maux[m.first]==0) continue;
        else res+=min(Maux[m.first],m.second);
    }
    printf("%lld\n",res);
    return 0;
}
