#include <bits/stdc++.h>
using namespace std;
struct cosa{
 long long int weight;
 bool operator<(const cosa &other)const{ return weight > other.weight; }
};

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        priority_queue<cosa> pq;
        long long  int n,res=0,num;
        cin>>n;
        for(int i=0; i<n;i++)
        {
            cin>>num;
            pq.push(cosa{num});
        }
        if(pq.size()==2)
        {
            cosa a=pq.top(); pq.pop(); cosa b=pq.top(); pq.pop();
            res+=(a.weight+b.weight);
        }
        else
        {
            while(pq.size()>1)
            {
                cosa a = pq.top(); pq.pop(); cosa b=pq.top(); pq.pop();
                res+=(a.weight+b.weight);
                pq.push(cosa{a.weight+b.weight});
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
