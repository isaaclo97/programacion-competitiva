#include <bits/stdc++.h>
using namespace std;
struct compare{
 int weight;
 bool operator<(const compare &other)const{ return weight > other.weight; }
};
int main()
{
    int cases,a;
    while(cin>>cases && cases!=0)
    {
        priority_queue<compare> pq;
        while(cases--)
        {
            cin>>a;
            compare aux;
            aux.weight=a;
            pq.push(aux);
        }
        compare aux1,aux2;
        int res=0,a,b;
        while(1)
        {
            aux1=pq.top();
            a=aux1.weight;
            pq.pop();
            aux2=pq.top();
            b=aux2.weight;
            res+=(a+b);
            pq.pop();
            aux1.weight=(a+b);
            if(pq.empty()) break;
            pq.push(aux1);
        }
        cout<<res<<endl;
    }
    return 0;
}
