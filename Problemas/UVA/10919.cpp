#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,m,n,c;
    while ( scanf ("%d", &k)==1 && k!=0 )
    {
        cin>>m;
        map <string, int> mapping;
        string a;
        for ( int i = 0; i < k; i++) {
            cin>>a;
            mapping [a] = 1;
        }
        int flag = 1;
        for ( int i = 0; i < m; i++ ) {
             cin>>n>>c;
            for ( int j = 0; j < n; j++ ) {
                cin>>a;
                if ( mapping [a]==1 ) c--;
            }
            if ( c > 0 ) flag=0;
        }
        if (flag==1) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
