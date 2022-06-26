#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases,hijos,padres,a;
    cin>>cases;
    while(cases!=0)
    {
        priority_queue<int> pq;
        int aux=cases;
        while(aux--)
        {
            cin>>hijos>>padres;
            int best = 0;
            for(int i=0; i<hijos;i++)
            {
                cin>>a;
                best = max(best,(padres*a));
            }
            pq.push(best);
        }
        for(int i=0; i<cases;i++)
        {
            if(i+1!=cases)
            cout<<pq.top()<<" ";
            else
                cout<<pq.top()<<endl;
            pq.pop();
        }
        cin>>cases;
    }
    return 0;
}
