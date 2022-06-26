
#include <bits/stdc++.h>
#define int_ long long int
using namespace std;

bool isInsideCircle(int_ cx, int_ cy, int_ r, int_ x, int_ y) {
    int_ dist = (x - cx) * (x - cx) + (y - cy) * (y - cy);
    return dist <= r * r;
}

int main(){
    int_ R,X,Y;
    while(scanf("%lld %lld %lld",&R,&X,&Y)==3){
        int_ total = 0; int_ cx=0,cy=0;
        while(R>=1){
            if(isInsideCircle(cx,cy,R,X,Y)) total++;
            int_ Yvalue = Y - cy;
            int_ Xvalue = X - cx;
            int_ Xvalue2 = -X + cx;
            //(R, 0), (−R, 0), (0, R) y (0, −R)
            if ((Yvalue == Xvalue) || (Yvalue == Xvalue2)) break;
            else if ((Yvalue > Xvalue) && (Yvalue > Xvalue2)) cy += R;
            else if ((Yvalue < Xvalue) && (Yvalue > Xvalue2)) cx += R;
            else if ((Yvalue < Xvalue) && (Yvalue < Xvalue2)) cy -= R;
            else cx -= R;
            R/=2;
        }
        printf("%lld\n",total);
    }
    return 0;
}
