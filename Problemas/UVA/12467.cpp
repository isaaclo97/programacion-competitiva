#include <bits/stdc++.h>
using namespace std;

vector<int> Z(string &s) {
    int n = s.size();
    int L, R;
    L = R = 0;
    vector<int> Z(n, 0);
    for (int i = 1; i < n; ++i){
        if (i < R) Z[i] = min(Z[i-L], R-i);
        else Z[i] = 0;
        while (Z[i] + i < n and s[Z[i]] == s[i+Z[i]]) ++Z[i];
        if (i+Z[i] > R){
            L = i;
            R = i + Z[i];
        }
    }
    return Z;
}

int main()
{
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        string s;
        cin>>s;
        int n = s.length();
        for(int i=n-1; i>=0; i--) s+=s[i];
        vector<int> R = Z(s);
        int sol = 0;
        int index,index2;
        for(unsigned int i=n;i<s.length();i++){
            if(R[i]>sol) { sol=R[i]; index=i; index2=R[i]+i-1;}
        }
        for(int i=index2; i>=index;i--) cout<<s[i];
        cout<<'\n';

    }
    return 0;
}
