#include <bits/stdc++.h>
using namespace std;

struct node{
  int P,C;
  double relation;
};
bool sortC(node a,node b)
{
    return a.relation<b.relation;
}
int main()
{
    int P,C;
    while(scanf("%d%d",&P,&C)==2 && (P!=0 || C!=0))
    {
        int arr[P];
        int arrAux[C];
        for(int i=0; i<P;i++) scanf("%d",&arr[i]);
        for(int i=0; i<C;i++) scanf("%d",&arrAux[i]);
        vector<node> V;
        for(int i=0; i<P;i++)
            for(int j=0; j<C;j++) V.push_back({arr[i],arrAux[j],(double)arr[i]/(double)arrAux[j]});
        sort(V.begin(),V.end(),sortC);
        for(unsigned int i=0; i<V.size();i++) if(i==0) printf("%d-%d",V[i].P,V[i].C); else printf(" %d-%d",V[i].P,V[i].C);
        printf("\n");
    }
    return 0;
}
