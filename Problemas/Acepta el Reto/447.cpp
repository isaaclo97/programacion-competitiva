#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

#ifndef getchar_unlocked
#define getchar_unlocked() (getchar())
#endif
inline void fastInput(int &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {

    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

int arr[4];
int cases,m;
bool BFS()
{
    bool visited[16][16][16][16];
    memset(visited,false,sizeof(visited));
    queue<vector<int>> q;
    vector<int> vals;
    for(int i=0; i<4;i++) vals.push_back(0);
    visited[0][0][0][0]=true;
    q.push(vals);
    while(!q.empty())
    {
        vector<int> actual = q.front(); q.pop();
        for(int i=0; i<m;i++) if(actual[i]==cases) return true;
        for(int i=0; i<m;i++)
        {
           if(arr[i]==0) continue; //Botella a 0
           if(actual[i]!=0) //Vaciar
           {
               int aux = 0;
               swap(actual[i],aux);
               if(!visited[actual[0]][actual[1]][actual[2]][actual[3]])
               {
                  visited[actual[0]][actual[1]][actual[2]][actual[3]]=true;
                  q.push(actual);
               }
               swap(actual[i],aux);
           }
           if(actual[i]!=arr[i]) //Llenar
           {
               int aux = arr[i];
               swap(actual[i],aux);
               if(!visited[actual[0]][actual[1]][actual[2]][actual[3]])
               {
                  visited[actual[0]][actual[1]][actual[2]][actual[3]]=true;
                  q.push(actual);
               }
               swap(actual[i],aux);
           }
           for(int j=0; j<m;j++) //Cambiar con cada uno posible
           {
               if(i==j || arr[i]==0 || arr[j]==0) continue;
               int l = max(0,actual[i]-(arr[j]-actual[j])); //Lo que resta
               int a = min(arr[j],actual[i]+actual[j]); //Lo que suma al otro
               swap(actual[i],l);
               swap(actual[j],a);
               if(!visited[actual[0]][actual[1]][actual[2]][actual[3]])
               {
                  visited[actual[0]][actual[1]][actual[2]][actual[3]]=true;
                  q.push(actual);
               }
               swap(actual[i],l);
               swap(actual[j],a);
           }
        }
    }
    return false;
}
int main()
{
    while(scanf("%d",&cases)==1 &&cases!=0)
    {
        cin>>m;
        int flag = 0,maximo=0;
        for(int i=0; i<m;i++) { cin>>arr[i]; if(arr[i]==cases) flag=1; maximo=max(arr[i],maximo);}
        if(maximo>=cases && flag==0)
        {
            if(m>1) if(BFS()) flag=1;
        }
        if(flag==1) cout<<"SI\n";
        else cout<<"NO\n";
    }
    return 0;
}
