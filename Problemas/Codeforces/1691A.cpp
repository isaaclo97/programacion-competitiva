
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--) {
        int n, res = 0;
        scanf("%d", &n);
        int num;
        for (int i = 0; i < n; i++){
            cin>>num;
            if (num % 2) res++;
        }
        cout<<min(res, n - res)<<endl;
    }
    return 0;
}
