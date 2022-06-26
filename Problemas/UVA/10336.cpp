#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int sx[]={1,-1,0,0}; //4 directions
int sy[]={0,0,1,-1};

const int VAL = 105;
bool visited[VAL][VAL];
char arr[VAL][VAL];
int c,r;
void dfs(int a,int b, char c_)
{
    visited[a][b]=true;
    for(int i=0;i<4;i++){
    int I=a+sx[i];
    int J=b+sy[i];
    if(I>=0 && I<r && J>=0 && J<c && !visited[I][J]&& arr[I][J]==c_){
       visited[I][J]=true;
    dfs(I,J,c_);
    }
    }
}
bool cmp(pair<char,int> a,pair<char,int> b)
{
    if(a.second == b.second) return a.first<b.first;
    return a.second > b.second;
}
int main()
{
    int aux,ca=1;
    cin>>aux;
    while(aux--)
    {
        map<char,int> M;
        set<char> S;
        scanf("%d%d",&r,&c);
        for(int i=0; i<r;i++)
         for(int j=0; j<c;j++) { cin>>arr[i][j]; S.insert(arr[i][j]);}
        for(auto s:S)
        {
        memset(visited,false,sizeof(visited));
        int cont = 0;
        for(int i=0; i<r;i++)
         for(int j=0; j<c;j++)
             if(arr[i][j]==s && !visited[i][j]) { dfs(i,j,s); cont++;}
        M[s]=cont;
        }

        vector<pair<char,int>> V;
        for(auto m:M)
            V.push_back(make_pair(m.first,m.second));
        sort(V.begin(), V.end(), cmp);
        printf("World #%d\n",ca++);
            for(auto v:V)
            printf("%c: %d\n",v.first,v.second);

    }
    return 0;
}
