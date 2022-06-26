#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,aux; cin>>n;
    vector<int> total;
    int res = 0;
    for(int i=0; i<n;i++)
    {
        cin>>aux;
        if(i!=0 && aux==1) {total.push_back(res); res=0;}
        res++;
    }
    total.push_back(res);
    cout<<total.size()<<'\n';
    for(unsigned int i=0; i<total.size();i++) if(i==0) cout<<total[i]; else cout<<" "<<total[i];
    return 0;
}
