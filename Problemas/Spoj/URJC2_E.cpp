#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,k,h,n,auxi,contador=0;
       cin>>t;
    while(t--){
        cin>>k>>h>>n;
        n++;
        int principal[k][n];
        for(int m=0;m<k;m++)
               {
                   for(int g=1;g<n;g++)
                   {
                       cin>>auxi;
                       contador+=auxi;
                       principal[m][g]=contador;
                   }
                   principal[m][n-n]=0;
                   contador=0;
               }
       int d, inicio,fin,estresados=0;
       cin>>d;
       while(d--){
           cin>>inicio>>fin;
           for(int i=0;i<k;i++){
                if((principal[i][fin]-principal[i][inicio - 1])>h)
                    estresados ++;
           }
           printf("%d - %d\n",estresados,k-estresados);
           estresados=0;
       }
    }
} 
