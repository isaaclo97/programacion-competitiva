#include <bits/stdc++.h>
using namespace std;

int nums[200005];
string letters[200005];
long long int n,k;

bool checkPossible(long long int capR){
    long long int total=0;
    long long int capE = capR*2;
    long long int acuR=0, acuE=0;
    for(int i = 0; i<n;i++){
        if(letters[i]=="R") {
            acuR+=nums[i];
            if(nums[i]>capR) return false;
            if(capR<acuR){
                acuR=nums[i];
                acuE=0;
                total++;
            }
        }
        else{
            acuE+=nums[i];
            if(nums[i]>capE) return false;
            if(capE<acuE){
                acuE=nums[i];
                acuR=0;
                total++;
            }
        }
    }
    if(acuR!=0 || acuE!=0) total++; //ultimo dia
    return total<=k;
}
int main(){
    while(scanf("%lld %lld",&k,&n)==2 && (n!=0 || k!=0)){
        long long int last = 0, first = 0;
        for(int i=0;i<n;i++) {
            cin>>nums[i]>>letters[i];
            last+=nums[i];
        }
        long long int res = last;
        while (first<last) {
            long long int middle = (first + last) / 2;
            if (checkPossible(middle)) {
                res=min(res,middle);
                last = middle;
            }
            else first = middle + 1;
        }
        printf("%lld\n",res);
    }
    return 0;
}