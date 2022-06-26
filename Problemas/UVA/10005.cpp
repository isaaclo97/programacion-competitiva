#include <bits/stdc++.h>
#define PI acos(-1.0)
#define EPS 1e-8
using namespace std;

struct point{
    double x,y;
    point(){x=y=0;}
    point(double _x,double _y){x=_x,y=_y;}
};

double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

bool circle2PtsRad(point p1, point p2, double r, point &c) {
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
              (p1.y - p2.y) * (p1.y - p2.y);
  double det = r * r / d2 - 0.25;
  if (det < 0.0) return false;
  double h = sqrt(det);
  c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
  c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
  return true; }
point circle(point &a, point &b, point &c) {
   static point ab, ac, o;
   static double a1, b1, c1, a2, b2, c2, D, D1, D2;
   ab.x = (a.x+b.x)/2, ab.y = (a.y+b.y)/2;
   ac.x = (a.x+c.x)/2, ac.y = (a.y+c.y)/2;
   a1 = a.x-b.x, b1 = a.y-b.y;
   c1 = a1*ab.x + b1*ab.y;
   a2 = a.x-c.x, b2 = a.y-c.y;
   c2 = a2*ac.x + b2*ac.y;
   D = a1*b2-a2*b1;
   D1 = c1*b2-c2*b1;
   D2 = a1*c2-a2*c1;
   o.x = D1/D;
   o.y = D2/D;
   return o;
}
double minCoverCircle(vector<point> p, int n) {
    point c;
    double cr = 0.0;
    int i, j, k;
    c = p[0];
    for(i = 1; i < n; i++) {
        if(dist(p[i], c) >= cr+EPS) {
            c = p[i], cr = 0;
            for(j = 0; j < i; j++) {
                if(dist(p[j], c) >= cr+EPS) {
                    c.x = (p[i].x+p[j].x)/2;
                    c.y = (p[i].y+p[j].y)/2;
                    cr = dist(p[i], c);
                    for(k = 0; k < j; k++) {
                        if(dist(p[k], c) >= cr+EPS) {
                            c = circle(p[i], p[j], p[k]);
                            cr = dist(p[i], c);
                        }
                    }
                }
            }
        }
    }
    return sqrt(cr);
}
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
      vector<point> V;
      double x,y,rad;
      for(int i=0; i<n;i++)
      {
          scanf("%lf%lf",&x,&y);
          V.push_back(point(x,y));
      }
      scanf("%lf",&rad);
      point aux;
      bool flag = false;
      int k;
      for(int i=0; i<n && !flag;i++)
          for(int j=i+1; j<n &&!flag;j++)
          {
              circle2PtsRad(V[i],V[j],rad,aux);
              for(k=0;k<n;k++)
                if(dist(V[k],aux) > rad) break;
              if(k==n) flag=true;
          }
      if(flag) printf("The polygon can be packed in the circle.\n");
      else printf("There is no way of packing that polygon.\n");
    }
    return 0;
}
