#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length(), ans = 0;
    string t, z, q;
    for(int i=0; i<n; i++){
        t += s[i];
        z = s[i];
        q = t;
        q.erase(0, 1);
        long long x = stoll(t);
        long long y = stoll(z);
        long long xx;
        if(!q.empty()) xx = stoll(q);
        else xx = 1;
        if(x % 3 == 0 || y%3==0 || xx % 3 == 0){ ans++; t.clear();}
        else if(t.length() >= 18) t.erase(0,1);
    }
    cout << ans;
    return 0;
}
