#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n,d;
    while(scanf("%d%d",&n,&d)==2 && (n!=0||d!=0))
    {
        vector<int> vec;
        for(int i=1; i<=n;i++) vec.push_back(i);
        int cnt = 0;
        int l = vec.size();
        while(l!=1)
        {
             cnt += d;
             cnt=cnt%l;
             vec.erase(vec.begin() + cnt);
             l--;
        }
        cout<<vec[0]<<'\n';
    }
    return 0;
}
