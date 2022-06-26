#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, up, down;
    cin>>T;
        while (T--) {
            cin>>n;
            bool yes = true;
            cin>>up>>down;
            int d = up - down;
            for (int i = 0; i < n - 1; i++) {
                cin>>up>>down;
                if (d != up - down)
                    yes = false;
            }
            if (yes) cout<<"yes\n";
            else cout<<"no\n";
            if (T) cout<<endl;
        }
    return 0;
}
