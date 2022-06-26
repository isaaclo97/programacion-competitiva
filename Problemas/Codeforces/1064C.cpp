#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    sort(s.begin(), s.end()); cout<<s<<'\n';
    /*
    int res = 0;
    char last = '\0';
    string au;
    for(int i=0;i<n;i++)
    {
        if(s[i]==last)  res+=au.length();
        else au = "";
        res++;
        last=s[i];
        au += s[i];
    }
    printf("%d\n",res);*/
    return 0;
}
