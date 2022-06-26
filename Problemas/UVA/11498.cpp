#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x, y, a, b;
    while(scanf("%d", &n) == 1 && n) {
        cin>>x>>y;
        while(n--) {
            cin>>a>>b;
            if(a == x || b == y)
                cout<<"divisa\n";
            else if(a > x && b > y)
                cout<<"NE\n";
            else if(a < x && b > y)
                cout<<"NO\n";
            else if(a < x && b < y)
                cout<<"SO\n";
            else
                cout<<"SE\n";
        }
    }
    return 0;
}
