#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
#define mp(_x,_y) make_pair((_x),(_y))
using namespace std;

struct point{
    double x,y;
    point(){x=y=0;}
    point(double _x,double _y){x=_x,y=_y;}

};

double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y); }

double cross(point o, point a, point b) {
    return (a.x-o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}
bool cmp(point a, point b) {
    if(a.y != b.y)
        return a.y <b.y;
    return a.x < b.x;
}
int CH(point p[], int n, point ch[]) {
    sort(p, p+n, cmp);
    int i, m = 0, t;
    for(i = 0; i < n; i++) {
        while(m >= 2 && cross(ch[m-2], ch[m-1], p[i]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    for(i = n-1, t = m+1; i >= 0; i--) {
        while(m >= t && cross(ch[m-2], ch[m-1], p[i]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    return m-1;
}

int main()
{
   string line;
   double x, y;
   char cha;
   while(getline(cin, line)) {
       point p[1005], ch[1005];
       int j =0;
       stringstream sin(line);
       while(sin >> cha >> x >> cha >> y >> cha)
       {
           p[j]=point(x,y); j++;
       }
       int n1 = CH(p,j,ch);
       int flag = 1;
       for(int i=0; i<=n1;i++)
           if(flag==1) { printf("(%g,%g)",ch[i].x,ch[i].y); flag++;}
           else printf(" (%g,%g)",ch[i].x,ch[i].y);
       printf("\n");
    }
    return 0;
}
