#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    while(n--) {
    int h,m,s;
    char a;
    cin>>h>>a>>m>>a>>s;
    int dur = h*3600+m*60+s;
    dur=86400-dur;
    h=dur/3600;
    dur=dur-(h*3600);
    m=dur/60;
    dur=dur-(m*60);
    s=dur;
    printf("%02d:%02d:%02d\n", h, m,s);
    }
    return 0;
}
