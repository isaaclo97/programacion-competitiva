#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    while(n--) {
    int h,m;
    char a,b,c;
    cin>>a>>c>>h;
    cin>>b>>c>>m;
    if(a=='D'&&b=='T')
        cout<<"V="<<h/m<<endl;
    else if(a=='T'&&b=='D')
        cout<<"V="<<m/h<<endl;
    else if(a=='T'&&b=='V')
               cout<<"D="<<h*m<<endl;
    else if(a=='V'&&b=='T')
        cout<<"D="<<h*m<<endl;
    else if(a=='V'&&b=='D')
               cout<<"T="<<m/h<<endl;
    else if(a=='D'&&b=='V')
        cout<<"T="<<h/m<<endl;
    }
    return 0;
}
