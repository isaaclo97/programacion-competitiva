#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
struct compare
{
  bool operator()(const int& l, const int& r) {return l > r;}
};
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2 && (n!=0 || m!=0))
    {
    int num,last=INF,p=0,p2=0,res;
    priority_queue<int> PQ;
    priority_queue<int,vector<int>,compare> PQ2;
    bool first=true;
    PQ.push(n); p++;
    for(int i=0; i<m*2;i++)
    {
        scanf("%d",&num);
        if(num<last) { PQ.push(num); p++;}
        else { PQ2.push(num);  p2++;}
        if(abs(p-p2)>1) {
          if(p>p2) { num=PQ.top(); PQ.pop();  PQ2.push(num); p--; p2++;}
          else{num=PQ2.top(); PQ2.pop();  PQ.push(num); p2--; p++;}
        }
        if(p2!=0) last=PQ2.top();
        if(i%2==1) {
         if(p<p2) res = PQ2.top();
         else if(p>p2) res = PQ.top();
         else res = max(PQ2.top(),PQ.top());
         if(first) cout<<res;
         else cout<<" "<<res;
         first=false;
        }
    }
    printf("\n");
    }
    return 0;
}
