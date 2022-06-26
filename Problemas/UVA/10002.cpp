#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
using namespace std;

struct point{
    double x,y;
    point(){x=y=0;}
    point(double _x,double _y){x=_x,y=_y;}
};

double cross(point o, point a, point b) {
    return (a.x-o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}
bool cmp(point a,point b){
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
double area(const vector<point> &P) {
  double result = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < (int)P.size()-1; i++) {
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    result += (x1 * y2 - x2 * y1);
  }
  return result / 2.0; }
vector<point> CH(vector<point> P){
    vector<point> res;
    sort(P.begin(),P.end(),cmp);
    int n = P.size();
    int m=0;
    for (int i=0;i<n;i++){
        while (m>1&&cross(res[m-2], res[m-1], P[i]) <= 0)res.pop_back(),m--;
        res.push_back(P[i]),m++;
    }
    for (int i = n-1, t = m+1; i >= 0; i--) {
        while (m>=t&&cross(res[m-2], res[m-1], P[i]) <= 0)res.pop_back(),m--;
        res.push_back(P[i]),m++;
    }
    return res;
}

point centroid(vector<point> g)		//center of mass
{
    double cx = 0.0, cy = 0.0;
    for(unsigned int i = 0; i < g.size() - 1; i++)
    {
        double x1 = g[i].x, y1 = g[i].y;
        double x2 = g[i+1].x, y2 = g[i+1].y;

        double f = x1 * y2 - x2 * y1;
        cx += (x1 + x2) * f;
        cy += (y1 + y2) * f;
    }
    double res = area(g);		//remove abs
    cx /= 6.0 * res;
    cy /= 6.0 * res;
    return point(cx, cy);
}


int main()
{
    int n;
    while(scanf("%d",&n)==1 && n>2)
    {
        vector<point> V;
        double x,y;
        for(int i=0; i<n;i++)
        {
            scanf("%lf%lf",&x,&y);
            V.push_back(point(x,y));
        }
        V = CH(V);
        point res = centroid(V);
        printf("%.3lf %.3lf\n",res.x,res.y);
    }
    return 0;
}
