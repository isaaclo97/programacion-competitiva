#include<bits/stdc++.h>
using namespace std;

int used[10500];
int BFS(int start, int target){
  queue<pair<int,int> > q;
  q.push(make_pair(start,0));
  while(!q.empty()){
    pair<int,int> current = q.front(); q.pop();
    if(current.first == target) return current.second;
    int sum = (current.first+1+10000)%10000;
    if(used[sum]==0)
    {
        used[sum]= 1;
      q.push(make_pair(sum ,current.second+1));
    }
    int mul = (current.first*2+10000)%10000;
    if(used[mul]==0)
    {
         used[mul]= 1;
      q.push(make_pair(mul,current.second+1));
    }
    int div = current.first/3;
    if(used[div]==0)
              q.push(make_pair((current.first/3),current.second+1));
  }
  return -1;
}


int main()
{
    int a,b;
    while(scanf("%d",&a)!=EOF)
    {
        cin>>b;
        memset(used,0,sizeof(used));
        cout<<BFS(a,b)<<endl;
    }
    return 0;
}
