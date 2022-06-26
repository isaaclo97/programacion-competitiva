#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases; string a; scanf("%d",&cases);
    while(cases--)
    {
        bool flag = true,flag1=true;
        cin>>a;
        set<char> S;
        for(unsigned int i=0; i<a.length();i++) S.insert(a[i]);
        int ant = 0;
        for(auto s:S){

            if(flag1) { ant = s; flag1=false; continue;}
            if(ant+1!=s) { flag=false; break;}
            ant = s;
        }
        if(a.length()==S.size() && flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
