#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int sx[]={1,-1,0,0,1,-1,-1,1}; //8 directions
int sy[]={0,0,1,-1,1,-1,1,-1};

bool visited[105][105];
vector<string> arr;
int c,r,total;
void dfs(int a,int b)
{
    visited[a][b]=true;
    for(int i=0;i<8;i++){
    int I=a+sx[i];
    int J=b+sy[i];
    if(I>=0 && I<r && J>=0 && J<c && !visited[I][J]&& arr[I][J]=='W'){
       visited[I][J]=true;
       total++;
    dfs(I,J);
    }
    }
}
int main()
{
    int aux;
    cin>>aux; cin.ignore();
    string s;
    getline(cin,s);
    while(aux--)
    {
        r=c=0;
        while(getline(cin,s))
        {
        if(s[0]!='W' && s[0]!='L') break;
        arr.push_back(s);
        r++;
        c=s.length();
        }
        int a,b;
        while(1){
        istringstream is2(s);
        is2>>a>>b;
        memset(visited,false,sizeof(visited));
        total = 1;
        dfs(a-1,b-1);
        cout<<total<<endl;
        getline(cin,s);
        if(s.empty()) break;
        }
        arr.clear();
        if(aux!=0) cout<<endl;
    }
    return 0;
}
