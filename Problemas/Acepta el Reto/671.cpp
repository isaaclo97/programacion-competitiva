#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0) {
        int arrl[n];
        int exit[n];
        for(int i=0; i<n;i++){
            scanf("%d %d",&arrl[i],&exit[i]);
        }
        sort(arrl, arrl+n);
        sort(exit, exit+n);
        int guests_in = 1, max_guests = 1;
        int cnt = exit[0]-arrl[0];
        int i = 1, j = 0;
        while (i < n && j < n){
            if (arrl[i] < exit[j]){
                guests_in++;
                if(guests_in==max_guests)
                    cnt+=exit[j]-arrl[i];
                if (guests_in > max_guests){
                    max_guests = guests_in;
                    cnt=exit[j]-arrl[i];
                }
                i++;
            }
            else{
                guests_in--;
                j++;
            }
        }
        printf("%d %d\n",max_guests,cnt);
    }
    return 0;
}