//Problema A Swerc 2017 Cakey McCakeFace

#include <bits/stdc++.h>
using namespace std;
int main()
{
 int cases;
 while(scanf("%d",&cases)!=EOF)
 {
     int m;  cin>>m;
     map<long long int, long long int> a;
     long long int arr1[cases]; long long int arr2[m];
     for(int i=0; i<cases;i++) cin>>arr1[i];
     for(int i=0; i<m;i++) cin>>arr2[i];

     for(int i=0; i<cases;i++)
         for(int j=0; j<m;j++)
         {
             long long int res = arr2[j]-arr1[i];
             if(res<=0) continue;
             if(a.insert(pair<long long int,long long int>(res,1)).second == false)
             {
                  long long int k = a.find(res)->second;
                  k++;
                  map<long long int,long long  int>::iterator it = a.find(res);
                  if (it != a.end())
                      it->second = k;
             }
         }
     map<long long int,long long int>::iterator it = a.begin();
     long long int sol=0, resul=0;
     for (it=a.begin(); it!=a.end(); ++it)
     {
         if(it->second>sol){ resul=it->first; sol=it->second;}
       // cout << it->first <<" "<< it->second << '\n';
     }
     cout<<resul<<endl;
 }
    return 0;
}