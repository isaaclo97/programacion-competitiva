#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

struct state
{
    bool mine;
    int value;
    int site;
    bool operator<(const state &other)const{ return value < other.value; }
};
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
      int time=0;
      queue<state> Q;
      priority_queue<state> PQ;
      int mine, total; cin>>total>>mine;
      for(int i=0; i<total;i++) {
          int num;
          state N;
          if(i==mine) N.mine=true;
          else N.mine=false;
          cin>>num; N.value=num; N.site=i;
          PQ.push(N); Q.push(N);}
      while(!Q.empty())
      {
          state actual = PQ.top();
          if(actual.mine) break;
          PQ.pop();
          for(unsigned int i=0; i<Q.size();i++)
          {
              state move = Q.front();
              Q.pop();
              if(move.site==actual.site) break;
              Q.push(move);
          }
          priority_queue<state> modify;
          queue<state> aux;
          aux = Q;
          for(unsigned int i=0; i<Q.size();i++)
          {
              state move = aux.front();
              aux.pop();
              modify.push(move);
          }
          PQ=modify;
          time++;
      }
      cout<<time+1<<endl;
    }
    return 0;
}
