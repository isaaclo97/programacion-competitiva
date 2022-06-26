#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> A, pair<int,int> B)
{
    return A.second<B.second;
}

vector<pair<int,int>> V;
vector<pair<int,int>> P;
vector<int> Paux;
int n,m,l;

int bb(int x)
{
    int first = 0, middle, last = m;
    int searched = x;
    while (first<=last) { middle = (first + last) / 2;
    if (searched == P[middle].second) return middle;
    else {
        if (P[middle].second > searched) last = middle - 1;
        else first = middle + 1;
    }
   }
   return middle+1;
}
int main()
{
    scanf("%d%d%d",&n,&m,&l);
    for(int i=0; i<n;i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        V.push_back({x,y});
    }

    int marcas[m+1]; memset(marcas,0,sizeof(marcas));
    int sol[m+1]; memset(sol,0,sizeof(sol));
    for(int i=0; i<m;i++)
    {
        int k;
        scanf("%d",&k);
        P.push_back({i,k});
        Paux.push_back(k);
    }
    sort(P.begin(),P.end(),compare);
    sort(Paux.begin(),Paux.end());
    for(int i=0; i<n;i++)
    {
        int x,y; x=V[i].first; y=V[i].second;
        int aux = l-y;
        if(aux<0) continue;
        if(aux==0)
        {
            //bbinaria pescadores con x
            int res = bb(x);
            if(P[res].second == x) {
                marcas[res]++;
                marcas[res+1]--;
            }
            continue;
        }
        int infer = x-aux;
        int super = x+aux;
        vector<int>::iterator low,up;
        low=std::lower_bound (Paux.begin(), Paux.end(),infer);
        up= std::upper_bound (Paux.begin(), Paux.end(),super);
        int resi = (low- Paux.begin());
        int ress = (up - Paux.begin());
        if(ress==m) marcas[m]--;
        if(P[ress].second==super) marcas[ress+1]--;
        else marcas[ress]--;
        marcas[resi]++;
    }
    int flag = 0;
    for(int i=0; i<m;i++)
    {
        //printf("M: %d\n",marcas[i]);
        flag+=marcas[i];
        sol[i]=flag;
    }
    int solv[m+1];
    for(int i=0; i<m;i++)
    {
      solv[P[i].first] = sol[i];
    }
    for(int i=0; i<m;i++)
    {
       printf("%d\n",solv[i]);
    }
    return 0;
}
