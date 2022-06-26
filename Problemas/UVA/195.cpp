#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

bool compare (char a, char b)
{
    bool minisculaA = true, minisculaB = true;
    if (a >= 'A' && a <= 'Z')  minisculaA = false;
    if (b >= 'A' && b <= 'Z')  minisculaB = false;
    if (minisculaA && minisculaB)  return a < b;
    if (!minisculaA && !minisculaB) return a < b;
    if (minisculaA)
    {
        a -= ('a'-'A');
        return a < b;
    }
    else
    {
        b -= ('a'-'A');
        return a <= b;
    }
}

int main(){
    int cases;scanf("%d",&cases);
    while(cases--){
        string s;
        cin>>s;
        sort(s.begin(),s.end(),compare);
        do{
            cout<<s<<endl;
        }while(next_permutation(s.begin(),s.end(),compare));
    }
 return 0;
}
