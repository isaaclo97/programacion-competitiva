#include<bits/stdc++.h>
using namespace std;
int main() {
    double n,b;
    while(scanf("%lf%lf",&n,&b) ==2) {
        double sol=0;
        int num=0;
        n/=1000000;
        while(n<b)
        {
            num++;
            sol+=n;
            n*=2;
        }
        cout<<num<<endl;
    }
    return 0;
}
