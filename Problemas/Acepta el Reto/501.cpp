#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main(){
  int td,ta,dd,da,no;
  while(scanf("%d%d%d%d%d",&td,&ta,&dd,&da,&no)==5)
  {
   int cd,ca;
   for(int i=0; i<no;i++)
   {
     cd=ca=0;
     int D = min(td,dd);
     int A = min(ta,da);
     //cout<<D<<A<<endl;
     vector<int> Av;
     vector<int> Dv;
     int aux;
     for(int i=0;i<D;i++) {cin>>aux; Dv.push_back(aux);}
     for(int i=0;i<A;i++) {cin>>aux; Av.push_back(aux);}
     sort(Av.begin(),Av.end(),greater<int>());
     sort(Dv.begin(),Dv.end(),greater<int>());
     //cout<<Av[0]<<" "<<Dv[0]<<endl;
     for(int i=0; i<min(Av.size(),Dv.size());i++)
     {
       if(Av[i]-Dv[i]>0) cd++;
       else ca++;
     }
     td-=cd;
     ta-=ca;
   }
   cout<<td<<" "<<ta<<endl;
  }
return 0;
}
