#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    string line;
    while(getline(cin,line))
    {
        queue<int> Q;
        stack<int> S;
        int flag=1,flag1=1;
        for(unsigned int i=0; i<line.length();i++)
        {
            if(line[i]=='*' && flag == 1) { int b = S.top(); S.pop(); int a = S.top(); S.pop();  S.push(a*b);}
            else if(line[i]=='/' && flag == 1) { int b = S.top(); S.pop(); int a = S.top(); S.pop();  if(b==0) flag=0; else S.push(a/b);  }
            else if(line[i]=='+' && flag == 1) { int b = S.top(); S.pop(); int a = S.top();  S.pop(); S.push(a+b); }
            else if(line[i]=='-' && flag == 1)  { int b = S.top(); S.pop(); int a = S.top(); S.pop(); S.push(a-b); }
            else if(flag==1) S.push(line[i]-48);

            if(line[i]=='*' && flag1 == 1) { int b1= Q.front(); Q.pop(); int a1=Q.front(); Q.pop(); Q.push(a1*b1); }
            else if(line[i]=='/' && flag1 == 1) {  int b1= Q.front(); Q.pop(); int a1=Q.front(); Q.pop();  if(b1==0) flag1=0; else Q.push(a1/b1);  }
            else if(line[i]=='+' && flag1 == 1) {  int b1= Q.front(); Q.pop(); int a1=Q.front(); Q.pop(); Q.push(a1+b1); }
            else if(line[i]=='-'&& flag1 == 1) {  int b1= Q.front(); Q.pop(); int a1=Q.front(); Q.pop(); Q.push(a1-b1);  }
            else if(flag1 == 1) Q.push(line[i]-48);
        }
        if(flag1==0 && flag==0) cout<<"ERROR = ERROR\n";
        else if(flag==0) cout<<"ERROR != "<< Q.front()<<'\n';
        else if(flag1==0) cout<<S.top() << " != ERROR\n";
        else if (Q.front() == S.top()) cout<<S.top()<<" = "<<Q.front()<<'\n';
        else cout<<S.top()<<" != "<<Q.front()<<'\n';
    }
    return 0;
}
