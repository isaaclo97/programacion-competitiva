#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main()
{
    int n;
     while (scanf("%d",&n) && n != 0){
         int s2 = 0;
         vector<int> v;
         while (n--) {
             int x; cin >> x;
             v.push_back(x);
             s2 += x;
         }
         int s1 = 0, cnt = 0;
         if (s1 == s2) cnt++;
         for (int i = 0; i < v.size(); i++) {
             s1 += v[i];
             s2 -= v[i];
             if (s1 == s2) cnt++;
         }
         cout << cnt << '\n';
     }
    return 0;
}
