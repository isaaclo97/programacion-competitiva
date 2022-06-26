#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases,num,last;
    char arr[71][71];
    while(scanf("%d",&cases)==1&&cases!=-1)
    {
       int maxi=0,mini=INF,actual,flag=5;
       memset(arr,0x20,sizeof(arr));
       cin>>last;
       actual=70-last;
       last=70-last;
       for(int i=0; i<cases;i++) //column
       {

           cin>>num; //row
           num=70-num;
           if(last==num)
           {
               if(flag==2) actual--;
               arr[actual][i]='_';
               flag=3;
           }
           else if(last>num)
           {
               if(flag!=3) actual--;
               arr[actual][i]='/';
               flag=2;
           }
           else if(last<num)
           {
               if(flag==3) actual++;
               arr[actual][i]='\\';
               flag=3;
           }
           last=num;
           mini=min(mini,actual);
           maxi=max(maxi,actual);
       }
       //print
       for(int i=mini; i<maxi+1;i++)
       {
           for(int j=0; j<cases;j++)
               cout<<arr[i][j];
           cout<<'\n';
       }
       cout<<"***\n";
    }
    return 0;
}
