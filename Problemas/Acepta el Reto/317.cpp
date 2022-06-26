
#include <bits/stdc++.h>
using namespace std;

string decode;
long long int DP[1005];
vector<string> V;
long long int MOD = 1000000007;

bool compare(string a, string b){
    return a.length()<b.length();
}
long long int solve(int idx) {
    if (idx == decode.length()) return 1;
    long long int &best = DP[idx];
    if (best != -1) return best%MOD;
    long long int res = 0;
    string compare = "";
    for (int i = 0; i < V.size(); i++) {
        if (V[i].size() + idx > decode.length()) break;
        //string compare = "";
        for (unsigned int j = compare.length(); j < V[i].length(); j++)
            compare += decode[idx + j];
        if (compare == V[i]) {
            res = (res% MOD + (solve(idx + V[i].size())% MOD)) % MOD;
        }
    }
    return best = res;
}

int main(){
    int n;
    while(scanf("%d",&n)==1 && n!=0) {
        string line;
        V.clear();
        for(int i=0; i<n;i++){
            cin>>line; V.push_back(line);
        }
        V.push_back("0");
        sort(V.begin(),V.end(),compare);
        cin>>decode;
        memset(DP, -1, sizeof(DP));
        printf("%lld\n", solve(0)%MOD);
    }
    return 0;
}
