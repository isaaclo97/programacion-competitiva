#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
long long bit[MAX];
 
long long query(int indx){
    long long sum = 0;
    while (indx) {
        sum += bit[indx];
        indx -= (indx & -indx);
    }
    return sum;
}
 
void update(int indx, int x){
   while (indx <= MAX) {
        bit[indx] += x;
        indx += (indx & -indx);
    }
}
 
int main() {
    int n,cases; scanf("%d",&cases);
    while(cases--)
    {
        cin.ignore();
        memset(bit,0,sizeof(bit));
        scanf("%d",&n);
        long long a[n], b[n];
        long long int inv = 0;
        for (int i = 0; i <n; i++)  scanf("%lld",&a[i]);
        //coordinate compression-O(nlog(n)) time
        for(int i=0;i<n;i++)
            b[i]=a[i];
        sort(b, b + n);
        for (int i = 0; i < n; i++)
            a[i] = int(lower_bound(b, b + n, a[i]) - b) + 1;
        for (int i = n-1; i >= 0; i--) {
            inv+=query(a[i]-1);
            update(a[i],1);
        }
        printf("%lld\n",inv);
    }
}
