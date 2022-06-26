#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int x,y,leak,fph;
    while (scanf("%d Fuel consumption %d",&x,&fph)==2 && (x!=0 || fph!=0)){
        y=leak=0;
        double res = 0.0, cur = 0.0;
        while(1)
        {
            scanf("%d", &y); cin>>s;
            cur += (y - x) * fph / 100.0;
            cur += (y - x) * leak;
            res = max(res, cur);
            if (s[0] == 'G' && s[1] == 'o') break;
            else if (s[0] == 'L') leak++ ;
            else if (s[0] == 'M') leak = 0;
            else if (s[0] == 'G') { cin>>s; cur = 0.0;}
            else { cin>>s; scanf("%d", &fph); }
            x = y;
        }
        printf("%.3lf\n", res);
    }
    return 0;
}
