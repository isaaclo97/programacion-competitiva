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
    double lx,ly,rx,ry,la,lb,ra,rb;
    while(cases--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&lx,&ly,&rx,&ry,&la,&lb,&ra,&rb);
        double areassr,areawsr,areausr;
        if(!hasIntersect(lx,ly,rx,ry,la,lb,ra,rb)) {lxsol=lysol=rxsol=rysol=0;}
        //printf("%lf %lf %lf %lf\n",lxsol,lysol,rxsol,rysol);
        areassr=abs(rysol-lysol)*abs(rxsol-lxsol);
        areawsr=abs(lx-rx)*abs(ly-ry); areawsr-=areassr;
        double aux =abs(la-ra)*abs(lb-rb); areawsr+=aux-areassr;
        areausr=100*100; areausr-=areassr; areausr-=areawsr;
        printf("Night %d: %0.lf %0.lf %0.lf\n",ca++,areassr,areawsr,areausr);
    }
    return 0;
}
