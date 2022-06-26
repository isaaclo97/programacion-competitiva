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

int cross(const point &O, const point &A, const point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

double area(const vector<point> &P) {
  double result = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < (int)P.size()-1; i++) {
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    result += (x1 * y2 - x2 * y1);
  }
  return fabs(result) / 2.0; }
double calc_area(vector<point> P) {
    double ans = 0;
    int i;
    for(i = 0; i < P.size()-1; i++)
        ans += P[i].x*P[i+1].y - P[i].y*P[i+1].x;
    return fabs(ans)/2;
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
    int n,ca=1;
    while(scanf("%d",&n)==1 && n!=0)
    {
        vector<point> P;
        double x,y;
        for(int i=0; i<n;i++)
        {
            scanf("%lf%lf",&x,&y);
            P.push_back(point(x, y));
        }
        P.push_back(P[0]);
        double val = area(P);
        P = CH(P);
        double res = calc_area(P);
        //printf("%.2lf %.2lf\n", val, res);
        printf("Tile #%d\n",ca++);
        printf("Wasted Space = %.2lf %%\n\n",(res-val)*100/res);

    }
    return 0;
}
