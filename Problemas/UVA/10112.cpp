#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
using namespace std;

struct point{
    double x,y;
    char c;
    point(){x=y=0; c='$';}
    point(double _x,double _y, char _c){x=_x,y=_y, c=_c;}
};


struct vec { double x, y;  // name: `vec' is different from STL vector
  vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {       // convert 2 points to vector a->b
  return vec(b.x - a.x, b.y - a.y); }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b) {  // returns angle aob in rad
  vec oa = toVec(o, a), ob = toVec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
  return cross(toVec(p, q), toVec(p, r)) > 0; }

double cross(point o, point a, point b) {
    return (a.x-o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}
bool cmp(point a,point b){
    return a.c<b.c;
}
bool inPolygon(point test, vector<point> g){
  bool result = false;
  for (unsigned i = 0, j = g.size() - 1; i < g.size(); j = i++) {
    if ((g[i].y > test.y) != (g[j].y > test.y) &&
        (test.x < (g[j].x - g[i].x) * (test.y - g[i].y) / (g[j].y-g[i].y) + g[i].x)) {
      result = !result;
     }
  }
  return result;
}
double area(vector<point> P) {
 return abs(0.5 * (((P[2].y - P[0].y)*(P[1].x - P[0].x)) - ((P[1].y - P[0].y)*(P[2].x - P[0].x))));
}
// double area = Math.abs(0.5*(((tri.g[2].y-tri.g[0].y)(tri.g[1].x-tri.g[0].x))-((tri.g[1].y-tri.g[0].y)(tri.g[2].x-tri.g[0].x))));
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        vector<point> V;
        vector<point> R;
        double x,y;
        char c;
        for(int i=0; i<n;i++)
        {
            cin.ignore();
            scanf("%c %lf %lf",&c,&x,&y);
            V.push_back(point(x,y,c));
        }
        double areaR = -INF;
        for(unsigned int i=0; i<V.size();i++)
            for(unsigned int j=i+1; j<V.size();j++)
                for(unsigned int k=j+1; k<V.size();k++)
                {
                    vector<point> T; T.push_back(V[i]); T.push_back(V[j]); T.push_back(V[k]);
                    int flag=0;
                    for(unsigned int m=0; m<V.size() && flag==0;m++)
                    {
                        if(m==i || m==j || m==k) continue;
                        if(inPolygon(V[m],T)) flag=1;
                    }
                    if(flag==0) {
                        double res = area(T); if(res>areaR) { areaR=res; R=T; }
                        //printf("%c %c %c %lf %lf\n",T[0].c,T[1].c,T[2].c,areaR, res);
                    }
                }
        sort(R.begin(),R.end(),cmp);
        for(auto v:R)
        {
            printf("%c",v.c);
        }
        printf("\n");
    }
    return 0;
}
