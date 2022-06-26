
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)==2 && (n!=0 || m!=0)){
        string arr; cin.ignore();
        int res = 0;
        cin>>arr;
        while(m!=0){
            int cnt = 0;
            for(int i=0; i<n;i+=2){
                if(arr[i]=='1' && arr[i+1]=='1') { arr[cnt]='1'; res++; }
                else if(arr[i]=='1' || arr[i+1]=='1') arr[cnt]='1';
                else arr[cnt]='0';
                cnt++;
            }
            m--; n/=2;
        }
        printf("%d\n",res);
    }
    return 0;
}
