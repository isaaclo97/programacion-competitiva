#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {
        int cases; cin>>cases;
        string va; cin>>va;
        int res = 0,cx=0;
        for(int i=0; i<cases;i++)
        {
            if(va[i]=='x') cx++;
            else { if(cx>2) res+=cx-2; cx=0;}
        }
        if(cx>2) res+=cx-2;
        cout<<res;
    return 0;
}
