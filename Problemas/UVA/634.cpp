#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define PI acos(-1.0)
using namespace std;

struct point{
    int x,y;
    point(){x=y=0;}
    point(int _x,int _y){x=_x,y=_y;}
    bool operator <(point other) const{
        if (fabs(x-other.x)>EPS)return x<other.x;
        return y<other.y;
    }bool operator ==(point other) const{
        return (fabs(x-other.x)<EPS)&&
        (fabs(y-other.y)<EPS);
    }
    point operator +(point other) const{
        return point(x+other.x,y+other.y);
    }point operator -(point other) const{
        return point(x-other.x,y-other.y);
    }
};

int cross(const point &O, const point &A, const point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool pointInsidePolygon(point P, vector<point> poly){
    int n = poly.size();
    bool in = 0;

    for(int i = 0,j = n - 1;i < n;j = i++){
        double dx = poly[j].x - poly[i].x;
        double dy = poly[j].y - poly[i].y;

        if((poly[i].y <= P.y + EPS && P.y < poly[j].y) || (poly[j].y <= P.y + EPS && P.y < poly[i].y))
            if(P.x - EPS < dx * (P.y-poly[i].y) / dy+poly[i].x)
                in ^= 1;
    }
    return in;
}

int main()
{

    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        vector<point> P;
        int x,y;
        for(int i=0; i<n;i++)
        {
            scanf("%d%d",&x,&y);
            P.push_back(point(x, y));
        }
        point query; scanf("%d%d",&query.x,&query.y);
        if(pointInsidePolygon(query,P)) printf("T\n");
        else printf("F\n");
    }
    return 0;
}
