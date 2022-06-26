#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

struct compare
{
  bool operator()(const int& l, const int& r) {return l > r;}
};
int main()
{
    int cases;
    while(scanf("%d",&cases)==1)
    {
    int num,flag=1,last,p=0,p2=0;
    priority_queue<int> PQ;
    priority_queue<int,vector<int>,compare> PQ2;
    bool first=true;
    for(int i=0; i<cases;i++)
    {
        cin>>num;
        if(num==0) {
            if(p==0&&p2==0) if(first) { cout<<"ECSA"; first=false; } else cout<<" ECSA";
            else
            {
             int res;
             if(p<p2) { res = PQ2.top();  PQ2.pop(); p2--;}
             else {res = PQ.top(); PQ.pop(); p--;}
             if(first) cout<<res;
             else cout<<" "<<res;
             first=false;
            }
        }
        else {
            if(flag==1) { PQ.push(num); flag=0; p++;}
            else {
                  if(num<last) { PQ.push(num); p++;}
                  else { PQ2.push(num);  p2++;}
                }
             }
        if(abs(p-p2)>1) {
            if(p>p2) { num=PQ.top(); PQ.pop();  PQ2.push(num); p--; p2++;}
            else{num=PQ2.top(); PQ2.pop();  PQ.push(num); p2--; p++;}
       }
       if(p2!=0) last=PQ2.top();
       else last=INF;
    }
    cout<<'\n';
    }
    return 0;
}
