#include <bits/stdc++.h>
using namespace std;

struct weapon{
    int n,m,pos;
};
bool compare(weapon e, weapon d)
{
    if(e.n<d.n) return true;
    else if(e.n>d.n) return false;
    else if(e.m<d.m) return false;
    else if(e.m>d.m) return true;
    return e.pos<d.pos;
}
int main()
{
    int life;
    while(scanf("%d",&life)==1 && life!=0)
    {
        int n; scanf("%d",&n);
        vector<weapon> v;
        for(int i=0; i<n;i++)
        {
            int inocentes,villanos; scanf("%d%d",&inocentes,&villanos);
            v.push_back({inocentes,villanos,i});
        }
        sort(v.begin(),v.end(),compare);
        int i;
        for(i=0; i<n && life>0;i++)
        {
            life-=v[i].m;
        }
        if(life>0) printf("MUERTE ESCAPA");
        else {
            for(int j=0; j<i;j++)
            {
                if(j==0) printf("%d",v[j].pos+1);
                else printf(" %d",v[j].pos+1);
            }
        }
        printf("\n");
    }
	return 0;
}
