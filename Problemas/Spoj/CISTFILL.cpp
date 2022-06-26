#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

struct Cis{
    int b,h,w,d;
};
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        Cis a;
        vector<Cis> vec;
        int aux;
        double V,totalVolum=0,lowLevel,highLevel,Level;
        cin>>aux;
        for(int i=0; i<aux;i++)
        {
            cin>>a.b>>a.h>>a.w>>a.d;
            totalVolum+=(a.h*a.w*a.d);
            vec.push_back(a);
        }
        cin>>V;
        if(totalVolum<V) cout<<"OVERFLOW\n";
        else
        {
            lowLevel = 0.0;
            highLevel = 1e7;
                        while(highLevel - lowLevel > 0.000001) {
                            Level = (highLevel + lowLevel)/2;
                            totalVolum = 0.0;
                            for(int i=0; i<aux;i++) {
                                if(vec[i].b >= Level) continue;
                                else if((vec[i].b < Level) && ((vec[i].b + vec[i].h) >= Level))
                                    totalVolum += ((Level - vec[i].b) * (vec[i].w) * (vec[i].d));
                                else if((vec[i].b + vec[i].h) < Level)
                                    totalVolum += ((vec[i].h) * (vec[i].w) * (vec[i].d));
                            }
                            if(totalVolum >= V) highLevel = Level;
                            else lowLevel = Level;

                        }
                        printf("%.2lf\n", Level);
        }
    }
    return 0;
}
