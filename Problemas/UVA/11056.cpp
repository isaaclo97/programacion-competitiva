#include <bits/stdc++.h>
using namespace std;

struct state{
  string name;
  long long int total;
};
bool comp(state a, state b)
{
    transform(a.name.begin(), a.name.end(), a.name.begin(), ::tolower);
    transform(b.name.begin(), b.name.end(), b.name.begin(), ::tolower);
    if(a.total==b.total) return lexicographical_compare(a.name.begin(),a.name.end(),b.name.begin(),b.name.end());
    return a.total<b.total;

}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        string name;
        vector<state> V;
        long long int m,s,ms,total=0;
        for(int i=0; i<n;i++)
        {
            cin>>name;
            scanf(" : %lld min %lld sec %lld ms",&m,&s,&ms); total=m*60000+s*1000+ms;
            V.push_back({name,total});
        }
        sort(V.begin(),V.end(),comp);
        int cont=0;
        for(auto v:V)
        {
            if(cont%2==0) printf("Row %d\n",cont/2+1);
            printf("%s\n",v.name.c_str());
            cont++;
        }
        printf("\n");
    }
    return 0;
}
