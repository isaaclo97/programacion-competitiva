#include <bits/stdc++.h>
using namespace std;

double lxsol, lysol, rxsol,rysol;

int hasIntersect(int lx, int ly, int rx, int ry, int la, int lb, int ra, int rb) {
    lx = lxsol = max(lx, la);
    ly = lysol = max(ly, lb);
    rx = rxsol = min(rx, ra);
    ry = rysol = min(ry, rb);
    return lx < rx && ly < ry;
}

int main()
{
    int cases,ca=1; scanf("%d",&cases);
    double lx,ly,rx,ry;
    while(cases--)
    {
        int n; scanf("%d",&n);
        bool flag=false;
        scanf("%lf%lf%lf%lf",&lxsol,&lysol,&rxsol,&rysol);
        for(int i=1;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&lx,&ly,&rx,&ry);
            if(!hasIntersect(lx,ly,rx,ry,lxsol,lysol,rxsol,rysol)) flag=true;
        }
        double areassr = abs(rysol-lysol)*abs(rxsol-lxsol);
        if(flag) areassr=0;
        printf("Case %d: %0.lf\n",ca++,areassr);
    }
    return 0;
}
