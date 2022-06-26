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
    int cases; scanf("%d",&cases);
    double lx,ly,rx,ry,la,lb,ra,rb;
    while(cases--)
    {
        string line; getline(cin,line);
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&lx,&ly,&rx,&ry,&la,&lb,&ra,&rb);
        if(hasIntersect(lx,ly,rx,ry,la,lb,ra,rb)) printf("%.0lf %.0lf %.0lf %.0lf\n",lxsol,lysol,rxsol,rysol);
        else printf("No Overlap\n");
        if(cases!=0) printf("\n");
    }
    return 0;
}
