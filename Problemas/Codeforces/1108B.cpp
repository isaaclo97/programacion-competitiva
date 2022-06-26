#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases; scanf("%d",&cases);
    int maxnum = -0x3f3f3f3f,nextnum=-0x3f3f3f3f;
    int arr[cases];
    map<int,int> M;
    map<int,int> Flag;
    for(int i=0; i<cases;i++)
    {
        scanf("%d",&arr[i]);
        maxnum=max(maxnum,arr[i]);
        M[arr[i]]++;
    }
    for(int i=0; i<cases;i++)
    {
        if(maxnum%arr[i]==0 && Flag[arr[i]]==0) { Flag[arr[i]]++; M[arr[i]]--; }
    }
    for(auto m:M)
        if(m.second!=0) nextnum=max(m.first,nextnum);
    printf("%d %d",maxnum,nextnum);
    return 0;
}
