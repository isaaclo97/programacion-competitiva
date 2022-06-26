#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    while(getline(cin,line))
    {
        stack<int> S;
        long long int R,A,V;
        R=A=V=0;
        for(unsigned int i=0; i<line.length();i++)
        {
            if(line[i]=='R') { R++; S.push(0);}
            else if(line[i]=='A' &&A<R && S.top()!=1) { A++; S.push(1);}
            else if(line[i]=='V' && R>0 && A>0 && S.top()==1) { V++; R--; A--; S.pop(); S.pop();}
            else { R=A=0; while(!S.empty()) S.pop();}
        }
        printf("%lld\n",V);
    }
    return 0;
}
