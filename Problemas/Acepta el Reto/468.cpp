#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases;
    while(scanf("%d",&cases)==1)
    {
        int diff = 0;
        int min,val2; cin>>min;
        for(int i=1; i<cases;i++)
        {
            cin>>val2;
            if(val2<min) min=val2;
            else diff=max(diff,val2-min);
        }
        cout<<diff<<'\n';
    }
  return 0;
}
