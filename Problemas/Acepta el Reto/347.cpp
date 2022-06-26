#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int mm1,mm2;
    while(scanf("%d%d",&mm1, &mm2)==2 && (mm1!=0||mm2!=0))
    {
        int cont=0;
        while(mm1 > 9 && mm2 >9)
        {
            int a;
            if (mm1 > mm2) {
                a = mm1 / mm2;
                mm1 -= mm2 * a;
            }
            else {
                a = mm2 / mm1;
                mm2 -= mm1 * a;
            }
            cont += a;
        }
        cout<<cont<<'\n';
    }
    return 0;
}
