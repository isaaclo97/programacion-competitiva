#include <bits/stdc++.h>
using namespace std;

bool ordenar(pair<int,int> A,pair<int,int> B)
{
    return A.second<B.second;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
         vector<pair<int,int>> V;
         for(int i=0; i<n;i++)
         {
         int h,m,s; scanf("%d:%d:%d",&h,&m,&s);
         int total = h*3600 + m*60+s;
          V.push_back(make_pair(i,total));
         }
         sort(V.begin(),V.end(),ordenar);
         int val = 1,valaux=1;
         vector<pair<int,int>> sol; sol.push_back(make_pair(val,V[0].first));
         for(int i=1; i<n;i++)
         {
            valaux++;
            if(V[i].second-1 == V[i-1].second || V[i].second == V[i-1].second) sol.push_back(make_pair(val,V[i].first));
            else { sol.push_back(make_pair(valaux,V[i].first)); val=valaux;}
         }
         sort(sol.begin(),sol.end(),ordenar);
         for(int i=0; i<n;i++)
         {
            cout<<sol[i].first<<'\n';
         }
    cout<<"---\n";
    }
    return 0;
}
