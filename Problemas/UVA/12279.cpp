#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n,number=1;
    while(cin>>t && t!=0) {
        int res=0;
       for(int i=0; i<t;i++)
       {
           cin>>n;
           if(n!=0)
               res++;
           else
               res--;
       }
       cout<<"Case "<<number<<": "<<res<<endl;
       number++;
    }
    return 0;
}
