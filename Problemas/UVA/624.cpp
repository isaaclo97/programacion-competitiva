#include <bits/stdc++.h>
using namespace std;

int arr[25];
int N,T,suma,cnt;
vector<int> V;
void sol(int i, int sum,int count,vector<int> R)
{
    if(i>T || sum>N) return;
    if(sum<=N && sum>=suma) { if((sum==suma && cnt<count) || sum>=suma) {V=R; cnt=count; suma=sum; }}
    sol(i+1,sum,count,R);
    R.push_back(arr[i]);
    sol(i+1,sum+arr[i],count+1,R);
}

int main()
{
    while(scanf("%d",&N)==1)
    {
        scanf("%d",&T);
        for(int i=0; i<T;i++) scanf("%d",&arr[i]);
        suma=cnt=0;
        vector<int> A; V.clear();
        sol(0,0,0,A);
        for(auto v:V) printf("%d ",v);
        printf("sum:%d\n",suma);
    }
    return 0;
}
