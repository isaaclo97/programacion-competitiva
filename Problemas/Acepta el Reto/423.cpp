#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases;
    while(scanf("%d",&cases)==1)
    {
        int res=0;
        int num;
        cin>>num;
        stack<int> pile;
        for(int i=0; i<num;i++) pile.push(1);
        while(!pile.empty())
        {
            cin>>num;
            if(num!=0)
            {
            int actual= pile.top();
            pile.pop();
            for(int i=0; i<num;i++) pile.push(actual+1);
            }
            else {int actual=pile.top(); if(actual>=cases)res++; pile.pop();}
        }
        cout<<res<<endl;
    }
    return 0;
}
