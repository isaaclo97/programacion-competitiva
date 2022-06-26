#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
using namespace std;

struct point{
    double x,y;
    point(){x=y=0;}
    point(double _x,double _y){x=_x,y=_y;}
    point operator-(point a)
    {
    point r;
    r.x=x-a.x; r.y=y-a.y;
    return r;
    }
    point operator+(point a)
    {
    point r;
    r.x=x+a.x; r.y=y+a.y;
    return r;
    }
    point operator*(double sc)
    {
    point r;
    r.x=x*sc; r.y=y*sc;
    return r;
    }
};
int orientation(point a,point b,point c){
    int v = (b.y-a.y) * (c.x-b.x) - (b.x-a.x) * (c.y-b.y);
    if(!v) return 0; //colinear
    return v>0?1:2; // clock or counterclock wise
}
//Comprueba si el punto q pertenece al segmento pr
bool onSegment(point p, point q, point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}
// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool intersect(point p1, point q1, point p2, point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}

int main()
{
    int n,cases; scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d",&n);
        double x,y,x_,y_;
        vector<pair<point,point>> V;
        for(int i=0; i<n;i++)
        {
            scanf("%lf %lf %lf %lf",&x,&y,&x_,&y_);
            V.push_back({point(x,y),point(x_,y_)});
        }
        int res=0;
        for(int i=0; i<n;i++)
        {
            int flag=1;
            for(int j=0;j<n && flag==1;j++)
            {
                if(j==i) continue;
                if(intersect(V[i].first,V[i].second,V[j].first,V[j].second)) flag=0;
            }
            if(flag==1) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
