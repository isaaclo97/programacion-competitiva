#include<bits/stdc++.h>
using namespace std;

int longest(string str)
{
  bool flag=true;
  unsigned int i=1;
  for(i=1; i<str.length();i++)
  {
      for(unsigned int m=0,k=0; m<str.length() && flag;m++,k=(k+1)%i)
          if(str[m]!=str[k]) flag=false;
      if(flag) break;
      flag=true;
  }
  return i;
}
int main(){
int cases;
  while(scanf("%d",&cases)==1 && cases!=0)
  {
  int arr[cases];
  string val = "";
  for(int i=0;i<cases;i++) scanf("%d",&arr[i]);
  for(int i=1;i<cases;i++) val+=(arr[i]-arr[i-1])+48;
  int size = longest(val);
  int n = cases%size;
  n--; if(n==-1) n=size-1;
  printf("%d\n",arr[cases-1]-48+val[n]);
  }
  return 0;
}
