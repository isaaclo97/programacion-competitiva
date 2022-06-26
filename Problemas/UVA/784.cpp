#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int sx[]={1,-1,0,0,1,-1,-1,1}; //8 directions
int sy[]={0,0,1,-1,1,-1,1,-1};

vector<string> arr;
bool visited[105][105];
void dfs(int a,int b)
{

    visited[a][b]=true;
    for(int i=0;i<8;i++){
    int I=a+sx[i];
    int J=b+sy[i];
    if(!visited[I][J] && arr[I][J]==' '){
    visited[I][J]=true;
    arr[I][J]='#';
    dfs(I,J);
    }
    }
}
int main()
{
    int aux;
    cin>>aux; cin.ignore();
    while(aux--)
    {
        string str;
        int flag=0;
        while(getline(cin, str), str.front() != '_') arr.push_back(str);
        memset(visited,false,sizeof(visited));
        for(unsigned int i = 0; i < arr.size()&&flag==0; i++)
            for(unsigned int j = 0; j<arr[i].size()&&flag==0; j++)
                if(arr[i][j] == '*')
                {
                    dfs(i, j);
                    arr[i][j]='#';
                    flag=0;
                }
        for(auto s: arr) cout<<s<<endl;
        cout<<str<<endl;
        arr.clear();

    }
    return 0;
}

