#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
using namespace std;

struct point{
    long long int x,y;
};

point arr[100005];
point res[100005];

long long int cross(const point &O, const point &A, const point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
bool cmp(point a, point b) {
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
int CH(int n) {
    sort(arr, arr+n,cmp);
    int i, m = 0, t;
    for (i = 0; i < n; i++) {
        //if == 0 is collinear
        while(m >= 2 && cross(res[m-2], res[m-1], arr[i]) < 0)
            m--;
        res[m++] = arr[i];
    }
    //n-2 para ignorar un punto que se repetira
    for (i = n-2, t = m+1; i >= 0; i--) {
        while(m >= t && cross(res[m-2], res[m-1], arr[i]) < 0)
            m--;
        res[m++] = arr[i];
    }
    return m-1;
}

int main()
{
   freopen("C:/Users/Isaac/Documents/QT/Entregar/in.txt","r",stdin);
   //freopen("C:/Users/Isaac/Documents/QT/Entregar/out.txt","w",stdout);

    int cases; scanf("%d",&cases);
    while(cases--)
    {
        int n,j=0;
        char c;
        scanf("%d",&n);
        for(int i=0; i<n;i++)
        {
            scanf("%lld %lld %c",&arr[j].x,&arr[j].y,&c);
            if(c=='Y') j++;
        }
        n = CH(j);
        printf("%d\n",n);
        for(int i=0; i<n;i++)
            printf("%lld %lld\n",res[i].x,res[i].y);
    }
    return 0;
}
