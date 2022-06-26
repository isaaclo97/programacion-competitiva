#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main()
{

    int d,p9,p1;
    while(scanf("%d%d%d",&d,&p9,&p1)==3)
    {
        priority_queue<int> pq9,pq1;
        int aux;
        for(int i=0; i<p9;i++) {scanf("%d",&aux); pq9.push(aux);}
        for(int i=0; i<p1;i++) {scanf("%d",&aux); pq1.push(aux);}
        vector<int> sol,auxpq9,auxpq1;
        while(pq9.size()>0 && pq1.size()>0)
        {
            int res = 0;
            for(int i=0; i<d;i++)
            {
                int fp9 = pq9.top(); pq9.pop();
                int fp1 = pq1.top(); pq1.pop();
                res+=min(fp9,fp1);
                if(fp9<fp1) auxpq1.push_back(fp1-fp9);
                else if(fp9>fp1)  auxpq9.push_back(fp9-fp1);
                if(pq1.size() == 0 || pq9.size() == 0) break;
            }
            for(unsigned int i=0; i<auxpq1.size();i++) pq1.push(auxpq1[i]);
            for(unsigned int i=0; i<auxpq9.size();i++) pq9.push(auxpq9[i]);
            auxpq1.clear(); auxpq9.clear();
            sol.push_back(res);
        }
        for(unsigned int i=0; i<sol.size();i++)
        {
            if(i==0) printf("%d",sol[i]);
            else printf(" %d",sol[i]);
        }
        printf("\n");
    }
    return 0;
}
