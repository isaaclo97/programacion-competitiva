#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {
    
    int n;
    while (scanf("%d",&n)==1 && n!=0) {
        int rails[n];
           while (cin >> rails[0] && rails[0]!=0) {
             int index = 0;
             stack<int> Q;
             for (int i = 1; i < n; i++) cin >> rails[i];
             for (int i = 1; i <= n; i++) {
               Q.push(i);
               while (!Q.empty() && rails[index] == Q.top()) {
                 index++;
                 Q.pop();
               }
             }
             if(Q.empty()) cout<<"Yes\n";
             else cout<<"No\n";
           }
           cout<<endl;
    }
    return 0;
}
