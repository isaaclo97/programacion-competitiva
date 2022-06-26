#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases,n;
    while(scanf("%d",&cases)==1 && cases!=0)
    {
     vector<int> v1,v2,v3;
     int cur,curA; cur=curA=0;
     for(int i=0; i<cases;i++)
     {
        scanf("%d",&n);
        if(n<0) v1.push_back(n);
        else v2.push_back(n);
        v3.push_back(n);
     }
     sort(v1.begin(),v1.end(),std::greater<int>());
     sort(v2.begin(),v2.end());
     for(int i=0; i<cases;i++)
     {
        if(v3[i]<0) { if(i==0) printf("%d",v1[cur]); else printf(" %d",v1[cur]); cur++; }
        else { if(i==0) printf("%d",v2[curA]); else  printf(" %d",v2[curA]);  curA++;}
     }
     printf("\n");
    }
    return 0;
}
