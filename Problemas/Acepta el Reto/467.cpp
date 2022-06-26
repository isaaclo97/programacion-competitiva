#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases; cin>>cases;
    while(cases--)
    {
        string X,a,Y; cin>>X>>a>>Y;
        string Xaux,Yaux;
        for(unsigned int i=0; i<X.length();i++) Xaux+=tolower(X[i]);
        for(unsigned int i=0; i<Y.length();i++) Yaux+=tolower(Y[i]);
        if(Xaux==Yaux) cout<<"TAUTOLOGIA\n";
        else cout<<"NO TAUTOLOGIA\n";
    }
    return 0;
}
