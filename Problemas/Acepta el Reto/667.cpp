#include <bits/stdc++.h>
using namespace std;

int main() {
    int year;
    while(scanf("%d",&year)==1 && year!=0){ //se puede 0000?
        int uva[10],total=1000000005;
        map<int,int> M;
        M[year%10]++; year/=10;
        M[year%10]++; year/=10;
        M[year%10]++; year/=10;
        M[year]++;
        for(auto m:M) M[m.first]*=3;
        for(int i=0;i<10;i++) scanf("%d",&uva[i]);
        for(auto m:M) total=min(total,uva[m.first]/M[m.first]);
        printf("%d\n",total);
    }
    return 0;
}