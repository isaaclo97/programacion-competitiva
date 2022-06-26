#include <bits/stdc++.h>
using namespace std;

bool visited[200500];
int cases;

bool check(int elem)
{
     return !((elem==0 && visited[elem+1]) || (elem == cases-1 && visited[cases-2]) || (elem != 0 && elem!=cases-1 && visited[elem+1] && visited[elem-1]));
}
int main()
{
    scanf("%d",&cases);
    int arr[cases];
    map<int,int> M;
    for(int i=0; i<cases;i++) { scanf("%d",&arr[i]); M[arr[i]]++; }
    int actual = 0,rep=0;
    for(auto m:M) if(m.second>actual) { actual=m.second; rep=m.first; }
    queue<int> index;
    memset(visited,false,sizeof(visited));
    for(int i=0; i<cases;i++)  if(arr[i]==rep) { visited[i]=true; index.push(i);}
    printf("%d\n",cases-actual);
    int test = cases-actual;
    while(!index.empty() && test!=0)
    {
        int elem = index.front(); index.pop();
        if(elem-1>=0 && arr[elem-1]>rep && !visited[elem-1]) { printf("2 %d %d\n",elem,elem+1); visited[elem-1]=true; if(check(elem-1)) index.push(elem-1);  test--; }
        if(elem+1<cases && arr[elem+1]>rep && !visited[elem+1]){ printf("2 %d %d\n",elem+2,elem+1);  visited[elem+1]=true; if(check(elem+1))  index.push(elem+1);  test--;}
        if(elem-1>=0 && arr[elem-1]<rep && !visited[elem-1]) { printf("1 %d %d\n",elem,elem+1); visited[elem-1]=true; if(check(elem-1))  index.push(elem-1);  test--;}
        if (elem+1<cases && arr[elem+1]<rep && !visited[elem+1]){ printf("1 %d %d\n",elem+2,elem+1);visited[elem+1]=true; if(check(elem+1))  index.push(elem+1);  test--; }
       if(check(elem)) index.push(elem);
    }
    return 0;
}
