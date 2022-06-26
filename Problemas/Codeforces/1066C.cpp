#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;cin>>q;
	int l=1,r=0,i;
	int arr[200009];
	while(q--)
	{
		char c; cin>>c>>i;
		if(c=='L') {l--;arr[i]=l;}
		else if(c=='R') {r++;arr[i]=r;}
		else {printf("%d\n",min(arr[i]-l,r-arr[i]));}
	}
return 0;
}
