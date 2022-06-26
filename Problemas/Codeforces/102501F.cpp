
#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define PI acos(-1.0)
typedef long long int ll;
struct point{
    double x,y;
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

double calc_area(vector<point> Pa) {
  double ans = 0;
  for (int i = 0; i < (int) Pa.size() - 1; i++)
    ans += Pa[i].x * Pa[i + 1].y - Pa[i].y * Pa[i + 1].x;
  return fabs(ans) / 2.0;
}

int main(){
    int cases; scanf("%d",&cases);
    double area = 0;
    while(cases--){
        int points; scanf("%d",&points);
        vector<point> V;
        for(int i=0; i<points;i++){
            int x,y; scanf("%d %d",&x,&y);
            V.push_back(point{x,y});
        }
        V.push_back(V[0]);
        area+=calc_area(V);
    }
    printf("%lld\n",(long long int)area);
}
