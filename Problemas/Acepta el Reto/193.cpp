#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

string reverse(string s)
{
    string sol = "";
    for(int i=s.length()-1; i>=0;i--) sol+=s[i];
    return sol;
}
bool check(int n)
{
    while(n!=0)
    {
        int a = n%10;
        if(a%2==0) return false;
        n/=10;
    }
    return true;
}
int main()
{
    string line;
    while(getline(cin,line))
    {
        if(line.length()==1 && line[0]=='0') break;
        string aux = to_string(stoi(reverse(line)));
        if(aux.length() != line.length()) cout<<"NO\n";
        else {
        int n = stoi(line); int n1= stoi(aux); int res = n+n1;
        if(check(res)) cout<<"SI\n";
        else cout<<"NO\n";
        }
    }
    return 0;
}
