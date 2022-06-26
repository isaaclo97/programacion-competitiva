#include <bits/stdc++.h>
using namespace std;

struct circleS{
    int x,y,r;
};

int circle(circleS a, circleS b)
{
    return (pow(abs(a.x-b.x),2)+pow(abs(a.y-b.y),2))<pow((a.r+b.r),2);
}

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int n; scanf("%d",&n);
        vector<circleS> V;
        for(int i=0; i<n;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            V.push_back({a,b,c});
        }
        int res = 0;
        for(int i=0; i<n;i++){
            for(int j=i+1;j<n;j++) if(circle(V[i],V[j])) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
