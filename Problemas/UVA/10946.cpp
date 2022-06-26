#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int sx[]={1,-1,0,0}; //4 directions
int sy[]={0,0,1,-1};

const int VAL = 150;
bool visited[VAL][VAL];
char arr[VAL][VAL];
int c,r,total;
void dfs(int a,int b, char ch)
{
    visited[a][b]=true;
    for(int i=0;i<4;i++){
    int I=a+sx[i];
    int J=b+sy[i];
    if(I>=0 && I<r && J>=0 && J<c && !visited[I][J]&& arr[I][J]==ch){
       visited[I][J]=true;
       total++;
        dfs(I,J,ch);
    }
    }
}
bool compare(pair<char,int> a,pair<char,int> b)
{
    if(a.second==b.second) return a.first<b.first;
    return a.second>b.second;
}
int main()
{
    int ca = 1;
    while(scanf("%d%d",&r,&c)==2 && (r!=0 || c!=0))
    {
        vector<pair<char,int>> V;
        memset(visited,false,sizeof(visited));
        for(int i=0; i<r;i++)
            for(int j=0; j<c;j++) cin>>arr[i][j];
        total=1;
        for(int i=0; i<r;i++)
            for(int j=0; j<c;j++) {
                if(!visited[i][j]&&arr[i][j]!='.') { dfs(i,j,arr[i][j]); V.push_back(make_pair(arr[i][j],total)); total=1;}
            }
        printf("Problem %d:\n",ca++);
        sort(V.begin(),V.end(),compare);
        for(auto v:V) cout<<v.first<<" "<<v.second<<endl;
    }
    return 0;
}
