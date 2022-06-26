#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

bool isBalanced(int pi, int di, int pd, int dd, int &w) {
    bool left = true;
    if (pi == 0) {
        int pii, dii, pdi, ddi;
        scanf("%d%d%d%d",&pii,&dii,&pdi,&ddi);
        left = isBalanced(pii, dii, pdi, ddi, pi);
    }

    bool right = true;
    if (pd == 0) {
        int pid, did, pdd, ddd;
        scanf("%d%d%d%d",&pid,&did,&pdd,&ddd);
        right = isBalanced(pid, did, pdd, ddd, pd);
    }
    w = pi + pd;
    return left && right && pi*di == pd*dd;
}
int main()
{
    int pd,pi,di,dd,w;
    while(scanf("%d%d%d%d",&pi,&di,&pd,&dd)==4 && (pi!=0||pd!=0||di!=0||dd!=0))
    {
       bool balanced=isBalanced(pi,di,pd,dd,w);
        if(balanced) cout<<"SI\n";
        else cout<<"NO\n";
    }
    return 0;
}
