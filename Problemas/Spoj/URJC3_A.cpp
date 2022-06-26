//CONCURSO URJC3 CLASIFICATORIO SWERC

//A Contar Constellations
#include <bits/stdc++.h>
using namespace std;

struct punto{
 long long int x;
 long long int y;
 long long int z;
};
int check[3010];
vector<punto> q;
long long int eucle;
int m=0;
punto a;
void dfs(int x, punto actual)
{
    check[x]=1;
    for(long long int i=0;i<q.size();i++)
    {
        if(!check[i])
        {
            long double myDistance=sqrt(pow(q[i].x-actual.x,2.0)+pow(q[i].y-actual.y,2.0)+pow(q[i].z-actual.z,2.0));
            if(myDistance<=eucle)
            {

                a.x = q[i].x;
                a.y = q[i].y;
                a.z = q[i].z;
            dfs(i,a);
            }
        }
    }
}

int main()
{
    long long int l,to,x,y,z,count;
    cin>>l;
    while(l--)
    {
        count = 0;
        memset(check,0,sizeof(check)); //Pone a 0 el array
        cin>>to>>eucle;
        for(int i=0; i<to;i++)
        {
        cin>>x>>y>>z;
         q.push_back(punto{x,y,z});
        }
        for(unsigned int i=0;i<q.size();i++)
        {
            if(!check[i])
            {
                check[i]=1;
                punto actual;
                actual.x = q[i].x;
                actual.y = q[i].y;
                actual.z = q[i].z;
                m=i;
                dfs(i,actual);
                count++;
            }
        }
        cout<<count<<"\n";
        q.clear();
    }
return 0;
}
