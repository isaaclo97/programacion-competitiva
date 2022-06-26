#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main()
{
    int N;
    while (scanf("%d",&N) && N != 0) {
            cin.ignore();
             map<string, int> m;
             string s, t;
             while (N--) {
                 getline(cin, s);
                 getline(cin, t);
                 m[s] += (t == "CORRECTO" ? 1 : -1);
             }
             for (auto &p : m)
                 if (p.second != 0)
                     cout<< p.first <<", "<< p.second<<'\n';

             cout << "---" << endl;
         }
    return 0;
}
