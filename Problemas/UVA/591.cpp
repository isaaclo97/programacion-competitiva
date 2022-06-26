#include<bits/stdc++.h>
using namespace std;

int main() {
    int cases,p=1;
    while(scanf("%d", &cases) && cases!=0) {
        int n=0,media,res=0;
        int arr[cases];
        for(int i=0; i<cases;i++)
        {
            cin>>arr[i];
            n+=arr[i];
        }
        media=n/cases;
        for(int i=0; i<cases;i++)
        {
            if(arr[i]>media)
                res+=(arr[i]-media);
        }
        cout<<"Set #"<<p<<"\nThe minimum number of moves is "<<res<<".\n\n";
        p++;
    }
   return 0;
}
