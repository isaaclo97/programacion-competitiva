#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases,num;
    while(scanf("%d",&cases)==1 && cases!=0)
    {
        map<int,int> M;
        for (int i=0; i<cases;i++)
        {
         cin>>num;
         M[num]++;
        }
        map<int,int>::iterator it = M.begin();
        int maxi = -INF,res=0;
       for (it=M.begin(); it!=M.end(); it++)
       {
           if(maxi<it->second) { maxi=it->second; res=it->first;}
       }
       cout<<res<<endl;
    }
    return 0;
}
