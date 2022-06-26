#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {
        int N;
        while (scanf("%d",&N)==1 && N ) {
            vector<int> v;
            for (int i = 0; i < N; i++) {
                int x;
                cin >> x;
                v.push_back(x);
            }
            int j = 0;
            for (int i = v.size() - 1; i >= 1; i--)
                if (v[i] == v[i-1]) {
                    j = i;
                    break;
                }
            v[j]++;
            for (int k = j+1; k < v.size(); k++)
                v[k] = v[j];
            for (int i = 0; i < v.size()-1; i++)
                cout << v[i] << " ";
            cout << v[v.size()-1] << endl;
        }
    return 0;
}
