#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main() {
    int i=18,ans=0,n;
    cin>>n;
        while (i++)
        {
            int x=i,sm=0;
            while (x) {sm+=x%10;x/=10;} //sum of the number
            if (sm==10) {ans++;if (ans==n) {cout<<i;break;}} 
        }
	return 0;
}


