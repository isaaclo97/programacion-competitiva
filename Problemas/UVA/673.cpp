#include<bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    cin.ignore();
    while(cases--)
    {
        string line;
        getline(cin,line);
        bool check = true;
        stack<char> S;
        for(unsigned int i=0; i<line.length()&&check;i++)
        {
            if(line[i]=='('||line[i]=='{'||line[i]=='[') S.push(line[i]);
            else if(!S.empty()&&((line[i]==')'&&S.top()=='(')||(line[i]=='}'&&S.top()=='{')||(line[i]==']'&&S.top()=='['))) S.pop();
            else check=false;
        }
        if(check && S.empty()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
