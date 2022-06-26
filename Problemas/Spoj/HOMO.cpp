#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

string check(int hete, int homo)
{
   if(hete>1 && homo==0) return "hetero";
   else if(homo>0 && hete<2) return "homo";
   else if(hete>1&&homo>0) return "both";
   return "neither";

}
int main()
{
int cases;
while(scanf("%d",&cases)==1)
{
    int hete=0,homo=0;
    map<int,int> M;
    string name;
    int num;
    for(int i=0; i<cases;i++)
    {
        cin>>name>>num;
        if(name=="insert") { M[num]++; if(M[num]==2) homo++; else if(M[num]==1) hete++; }
        else
            if(M[num]>1) {M[num]--; if(M[num]==1) homo--; }
            else if(M[num]==1){ M.erase(num); hete--;}
        cout<<check(hete,homo)<<"\n";
    }
}
return 0;
}
