#include <bits/stdc++.h>
using namespace std;
vector<int> R;
vector<int> L;
char flip(char side){
if (side == 'L') return 'R'; else return 'L';
}
void split(int target, char side){
    if (target ==0) return;
    int power3 =1;
    while (power3<target) power3=power3*3;
    if (target == power3) {if(side=='L') L.push_back(target); else R.push_back(target); return;}
    if (target <= power3/2) {if(side=='L') L.push_back(power3/3); else R.push_back(power3/3); split(target-power3/3, side);}
    else {if(side=='L') L.push_back(power3); else R.push_back(power3); split(power3-target, flip(side)); }
}

int main()
{
    int target;
    while(scanf("%d",&target)==1)
    {
    split(target, 'L');
    reverse(L.begin(),L.end());
    reverse(R.begin(),R.end());
    for(auto a: L) cout<<a<<" ";
    cout<<"==X== ";
    for(auto b:R) cout<<b<<" ";
    cout<<"patatas\n";
    R.clear();
    L.clear();
    }
    return 0;
}
