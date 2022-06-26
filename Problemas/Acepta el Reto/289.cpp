#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

struct data{
    long long int w;
    bool operator<(const data &other)const{
        return w > other.w;
    }
};


int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        priority_queue<data> pq;
        long long int num,res=0;
        for(int i=0; i<n;i++)  {scanf("%lld",&num); pq.push(data{num});}
        if(n!=1)
        {
            while(!pq.empty())
            {
                long long int s;
                data sum = pq.top(); s=sum.w; pq.pop(); sum=pq.top(); pq.pop(); s+=sum.w;
                if(!pq.empty()) pq.push(data{s});
                res+=s;
            }
            printf("%lld\n",res);
        }
        else printf("0\n");
    }
    return 0;
}
