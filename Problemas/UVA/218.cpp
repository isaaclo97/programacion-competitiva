#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define PI acos(-1.0)
using namespace std;

struct point{
    double x,y;
    point(){x=y=0;}
    point(double _x,double _y){x=_x,y=_y;}
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

double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y); }

double perimeter(const vector<point> &P) {
  double result = 0.0;
  for (int i = 0; i < (int)P.size()-1; i++)
    result += dist(P[i], P[i+1]);
  return result; }

double cross(point o, point a, point b) {
    return (a.x-o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}

vector<point> CH(vector<point> P){
    vector<point> res;
    sort(P.begin(),P.end());
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

int main()
{
    int c = 1,n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        if(c!=1) printf("\n");
        vector<point> P;
        double x,y;
        for(int i=0; i<n;i++)
        {
            scanf("%lf%lf",&x,&y);
            P.push_back(point(x, y));
        }
        P = CH(P);
        reverse(P.begin(),P.end());
        printf("Region #%d:\n",c++);
        for(unsigned int i = 0; i<P.size(); i++)
        {
            //printf("PUNTO(%3.lf,%.3lf)",P[i].x,P[i].y);
            if(i==0) printf("(%.1lf,%.1lf)",P[i].x,P[i].y);
            else printf("-(%.1lf,%.1lf)",P[i].x,P[i].y);
        }
        if(P.size()==1) printf("-(%.1lf,%.1lf)",round(P[0].x*10)/10,round(P[0].y*10)/10);
        printf("\nPerimeter length = %.2lf\n",perimeter(P));
    }
    return 0;
}
