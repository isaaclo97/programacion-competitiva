#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {
    
    int n,ca=1; cin>>n;
    while (n--) {
        int arr[3];
        int T1,T2,F,A; cin>>T1>>T2>>F>>A>>arr[0]>>arr[1]>>arr[2];
        sort(arr,arr+3);
        int res = T1+T2+F+A+(int)(arr[2]+arr[1])/2;
        printf("Case %d: ",ca++);
        if(res>=90) cout<<"A"<<'\n';
        else if(res>=80) cout<<"B"<<'\n';
        else if(res>=70) cout<<"C"<<'\n';
        else if(res>=60) cout<<"D"<<'\n';
        else cout<<"F"<<'\n';
    }
    return 0;
}
