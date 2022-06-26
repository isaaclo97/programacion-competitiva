#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0)
    {
        map<string,int> M;
        string name;
       for(int i=0; i<cases;i++) { cin>>name; M[name]++;}
       int n; cin>>n;
       for(int i=0; i<n;i++) { cin>>name; cout<<M[name]+1<<'\n'; M[name]++;}
    }
return 0;
}
