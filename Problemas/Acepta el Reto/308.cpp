#include<bits/stdc++.h>
using namespace std;
map<pair<string,int>,bool> M;

bool solve(string s, char a) {
    int len = s.length();
    if (len == 0) return 0;
    if (len == 1)  return s[0] == a;
    if(M.count({s,a})!=0) {
        //cout<<"PODA\n";
        return M[{s,a}];
    }
    bool check = 0;
    for (int i = 1; i < len; i++)  {
        string first = s.substr(0, i);
        string second = s.substr(i, len - i);
        switch (a) {
            case 'a': {
                check = check || (solve(first, 'a') && solve(second, 'c'));
                check = check || (solve(first, 'b') && solve(second, 'c'));
                check = check || (solve(first, 'c') && solve(second, 'a'));
                break;
            }
            case 'b': {
                check = check || (solve(first, 'a') && solve(second, 'a'));
                check = check || (solve(first, 'a') && solve(second, 'b'));
                check = check || (solve(first, 'b') && solve(second, 'b'));
                break;
            }
            case 'c': {
                check = check || (solve(first, 'b') && solve(second, 'a'));
                check = check || (solve(first, 'c') && solve(second, 'b'));
                check = check || (solve(first, 'c') && solve(second, 'c'));
                break;
            }
        }
        if (check) break;
    }
    return M[{s,a}]=check;
}

int main() {
    string s;
    while(getline(cin,s)) {
        M.clear();
        if(solve(s, 'a')) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}