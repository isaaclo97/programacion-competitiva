#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
using namespace std;

struct point{
    double x,y,radio; char c;
    point(){x=y=radio=0; c='&';}
    point(double _x,double _y, double _radio, char _c){x=_x,y=_y; radio=_radio; c=_c;}
};

struct vec { double x, y;  // name: `vec' is different from STL vector
  vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {       // convert 2 points to vector a->b
  return vec(b.x - a.x, b.y - a.y); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool collinear(point p, point q, point r) {
  return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }
bool inPolygon(point P, vector<point> poly){
    int n = poly.size();
    bool in = 0;

    for(int i = 0,j = n - 1;i < n;j = i++){
        double dx = poly[j].x - poly[i].x;
        double dy = poly[j].y - poly[i].y;

        if((poly[i].y <= P.y + EPS && P.y < poly[j].y) || (poly[j].y <= P.y + EPS && P.y < poly[i].y))
            if(P.x - EPS < dx * (P.y-poly[i].y) / dy+poly[i].x)
                in ^= 1;
    }
    for(int i=0; i<n-1;i++)
        if(collinear(poly[i],poly[i+1],P)) return false;
    if(collinear(poly[0],poly[n-1],P)) return false;
    return in;
}

int insideCircle(point p, point c, double r) { // all integer version
  double dx = p.x - c.x, dy = p.y - c.y;
  double Euc = dx * dx + dy * dy, rSq = r * r;             // all integer
  return Euc < rSq ? 0 : Euc == rSq ? 1 : 2; } //inside/border/outside

int main()
{
    vector<point> V[9];
    double x,y,radio;
    char c;
    int i=0;
    while(cin>>c && c!='*')
    {
        if(c=='r') {
            double x1,y1;
            scanf("%lf%lf",&x,&y); scanf("%lf%lf",&x1,&y1);
            V[i].push_back(point(x,y1,0,c));
            V[i].push_back(point(x,y,0,c));
            V[i].push_back(point(x1,y,0,c));
            V[i].push_back(point(x1,y1,0,c));
        }
        else if(c=='c') {scanf("%lf%lf%lf",&x,&y,&radio);  V[i].push_back(point(x,y,radio,c));}
        else if(c=='t') {
            scanf("%lf%lf",&x,&y);  V[i].push_back(point(x,y,0,c));
            scanf("%lf%lf",&x,&y);  V[i].push_back(point(x,y,0,c));
            scanf("%lf%lf",&x,&y);  V[i].push_back(point(x,y,0,c));
        }
        i++;
    }
    int j=1,n=i;
    while(scanf("%lf %lf", &x,&y)==2 && (x!= 9999.9 || y!=9999.9))
    {
        int flag=1;
        for(int i=0;i<n;i++)
        {
            if(V[i][0].c == 'c')
            {
                int n = insideCircle(point(x,y,0,'.'),V[i][0],V[i][0].radio);
                if( n == 0) { flag++; printf("Point %d is contained in figure %d\n",j,i+1);}
            }
            else if(inPolygon(point(x,y,0,'.'),V[i])) {flag++; printf("Point %d is contained in figure %d\n",j,i+1);}
        }
        if(flag==1) printf("Point %d is not contained in any figure\n",j);
        j++;
    }
    return 0;
}
