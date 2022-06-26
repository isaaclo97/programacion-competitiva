#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int n,d,a[101],ans=INF;
int main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int l=1;l<=100;l++){
		int now=0;
		for(int j=1;j<=n;j++) 
            if(a[j]<l||a[j]>l+d) now++;
		if(now<ans) ans=now;
	}
	cout<<ans;
    return 0;
}
