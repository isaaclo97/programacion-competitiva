#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int nu; cin>>nu; int resu=0;
    int num[nu];
    map<long long int,int> M;
    for(int i=0; i<nu;i++) {  cin>>num[i]; M[num[i]]++; }
    for (int i = 0; i < nu; i++)
    {
        int flag=0;
        for (int k = 0; k < 32 && flag==0; k++) {
            int x = (1 << k) - num[i];
            if(M.count(x) && (M[x] > 1 || (M[x] == 1 && x != num[i]))) flag=1;
        }
        if(flag==0) resu++;
    }
    cout<<resu<<'\n';
    return 0;
}
