#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-10
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
};

point arr[100005];
point res[100005];


double cross(const point &O, const point &A, const point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

int pointInsidePolygon(point p,int n) {
    if (n < 3) return false;
    if (cross(res[0], p, res[1]) > EPS) return false;
    if (cross(res[0], p, res[n-1]) < -EPS) return false;

    int l = 2, r = n-1;
    int line = -1;
    while (l <= r) {
        int mid = (l + r)>>1;
        if (cross(res[0],p, res[mid]) > -EPS) {
            line = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return cross(res[line-1], p, res[line]) < EPS;
}

int CH(int n) {
    sort(arr, arr+n);
    int i, m = 0, t;
    for (i = 0; i < n; i++) {
        while(m >= 2 && cross(res[m-2], res[m-1], arr[i]) <= 0)
            m--;
        res[m++] = arr[i];
    }
    for (i = n-1, t = m+1; i >= 0; i--) {
        while(m >= t && cross(res[m-2], res[m-1], arr[i]) <= 0)
            m--;
        res[m++] = arr[i];
    }
    return m-1;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        double x,y;
        for(int i=0; i<n;i++)
        {
            scanf("%lf %lf",&x,&y);
            arr[i] = point(x, y);
        }
        int resn = CH(n);
        scanf("%d",&n);
        int res = 0;
        for(int i=0; i<n;i++)
        {
           point query; scanf("%lf%lf",&query.x,&query.y);
           res+=pointInsidePolygon(query,resn);
        }
        printf("%d\n",res);
    }
    return 0;
}
