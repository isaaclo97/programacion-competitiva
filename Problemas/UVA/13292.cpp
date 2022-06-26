#include <bits/stdc++.h>
#define EPS 10e-9
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define FOR(i, a, b) for(int i = (a); i < int(b); i++)
#define trav(i, v) for(auto &i : v)
#define has(c, e) ((c).find(e) != (c).end())
#define sz(c) int((c).size())
#define all(c) c.begin(), c.end()
#define debug(x) cerr << #x << ": " << x << endl;

typedef double T;
template<class T>
struct P {
    T x, y;

    explicit P(T a = 0, T b = 0) : x(a), y(b) {
    }

    bool operator<(P p) const {
        return tie(x, y) < tie(p.x, p.y);
    }

    bool operator==(P p) const {
        return tie(x, y) == tie(p.x, p.y);
    }

    P operator+(P p) const {
        return P(x + p.x, y + p.y);
    }

    P operator-(P p) const {
        return P(x - p.x, y - p.y);
    }

    P operator*(T d) const {
        return P(x*d, y * d);
    }

    P operator/(T d) const {
        return P(x / d, y / d);
    }

    T dot(P p) const {
        return x * p.x + y * p.y;
    }

    T cross(P p) const {
        return x * p.y - y * p.x;
    }

    T cross(P a, P b) const {
        return (a - * this).cross(b - * this);
    }

    T dist2() const {
        return x * x + y*y;
    }

    double dist() const {
        return sqrt((double) dist2());
    }
    // angle to x-axis in interval [-pi, pi]

    double angle() const {
        return atan2(y, x);
    }

    P unit() const {
        return *this / dist();
    } // makes dist()=1

    P perp() const {
        return P(-y, x);
    } // rotates +90 degrees

    P normal() const {
        return perp().unit();
    }
    // returns P rotated ’a’ radians ccw around the origin

    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
};

template <class P>
double cross(P o, P a, P b) {
    return (a.x-o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}
template <class P>
double cross2(P a, P b) {
    return a.x * b.y - a.y * b.x;
}

template <class P>
double dist(P p1, P p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y); }

template <class P>
int CH(int n, P p[], P ch[]) {
    sort(p, p+n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        while (m >= 2 && cross(ch[m-2], ch[m-1], p[i]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    for (int i = n-1, t = m+1; i >= 0; i--) {
        while (m >= t && cross(ch[m-2], ch[m-1], p[i]) <= 0)
            m--;
        ch[m++] = p[i];
    }
    return m-1;
}

struct vec {
    double x, y;

    vec(double _x, double _y) : x(_x), y(_y) {
    }
};
template <class P>
vec toVec(P a, P b) {
    return vec(b.x - a.x, b.y - a.y);
}

double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
    return v.x * v.x + v.y * v.y;
}

vec scale(vec v, double s) { // nonnegative s = [<1 .. 1 ..>1]
    return vec(v.x * s, v.y * s);
}// shorter.same.longer

template <class P>
P translate(P p, vec v) { // translate p according to v
    return P(p.x + v.x, p.y + v.y);
}
template <class P>
double distToLine(P p, P a, P b, P &c) {
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // translate a to c
    return dist(p, c);
}
template <class P>
double distToLineSegment(P p, P a, P b, P &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {
        c = P(a.x, a.y); // closer to a
        return dist(p, a);
    }
    if (u > 1.0) {
        c = P(b.x, b.y); // closer to b
        return dist(p, b);
    }
    return distToLine(p, a, b, c);
} // run distToLine as above

template <class P>
double polygonDiameter(int n, P pt[]) {
    if (n <= 2) return 0;
    double ret = 1e+60;
    P aux;
    pt[n]=pt[0];
    //int n =  pt.size()-1; //just end added
    for (int i = 0, j = 0; i <n; i++) {
            while (cross(pt[i], pt[i+1], pt[j+1]) >= cross(pt[i], pt[i+1], pt[j]))
                j = (j+1)%n;
            double dist = distToLineSegment(pt[j], pt[i], pt[i+1],aux);
            ret = min(ret, dist);
        }
    return ret;
}
int main()
{
    int n,r;
    while(scanf("%d%d",&n,&r)==2)
    {
        P<double> pt[262144], ch[262144];
        double x,y;
        for(int i=0; i<n;i++)
        {
            scanf("%lf%lf",&x,&y); pt[i] = P<double>{x,y};
        }
        n = CH(n,pt,ch);
        double sol = polygonDiameter(n,ch);
        printf("%.17lf\n",sol);
    }
    return 0;
}
