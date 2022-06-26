#include <bits/stdc++.h>
using namespace std;

int inverso(int n)
{
    string a = to_string(n);
    for(int i=a.length();i<4;i++) a='0'+a;
    string aux = "";
    for(int i=3;i>=0;i--) aux+=a[i];
    int num = stoi(aux);
    return num;
}

int main()
{
    int n,m;
    map<int,int> M;
    for(int i=0; i<=10000;i++) M[i]=inverso(i);
    while(scanf("%d%d",&n,&m)==2 && (n!=0||m!=0))
    {
       int count = 0;
       for(int i=1;i<=n;i++)
       {
           int value = M[i]+i;
           if(value<=n && value>=m) count++;
       }
       cout<<n<<" "<<m<<" "<<count<<endl;
    }
    return 0;
}
/*
1001 1000
2100 2000
5324 4999
0 0
*/
