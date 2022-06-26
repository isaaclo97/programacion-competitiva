#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define EPS 1e-18
#define PI acos(-1.0)
using namespace std;

struct point{
    double x,y;
    point(){x=y=0;}
    point(double _x,double _y){x=_x,y=_y;}
};

double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y); }

int main()
{
    string line;
    int ca=1;
    while(getline(cin,line) && line!="END")
    {
       vector<string> v;
       //split
       char *token = strtok(strdup(line.c_str()), ",");
       while (token != NULL)
       {
           v.push_back(token);
           token = strtok(NULL, ",");
       }
       int n = v.size();
       v[n-1] = v[n-1].substr(0,v[n-1].length()-1);
       int num; string l;
       point res;
       for(int i=0; i<n;i++)
       {
           //read string
           stringstream sin(v[i]);
           sin>>num>>l;
           if(l=="N") res.y+=num;
           else if(l=="NE") { res.x+=num*sqrt(2)/2; res.y+=num*sqrt(2)/2; }
           else if(l=="E") res.x+=num;
           else if(l=="SE") { res.x+=num*sqrt(2)/2; res.y-=num*sqrt(2)/2; }
           else if(l=="S") res.y-=num;
           else if(l=="SW") { res.y-=num*sqrt(2)/2; res.x-=num*sqrt(2)/2; }
           else if(l=="W") res.x-=num;
           else if(l=="NW") {res.y+=num*sqrt(2)/2; res.x-=num*sqrt(2)/2;}
       }
       printf("Map #%d\nThe treasure is located at (%.3lf,%.3lf).\n",ca++,res.x,res.y);
       printf("The distance to the treasure is %.3lf.\n\n",dist(res,point(0,0)));
    }
    return 0;
}
