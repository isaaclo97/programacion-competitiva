
#include <bits/stdc++.h>
using namespace std;

long long int getOF(long long int leftValue, long long int middle, long long int rightValue) {
    long long int maxValue = max(leftValue, max(rightValue, middle));
    long long int minValue = min(leftValue, min(rightValue, middle));
    long long int current = maxValue - minValue;
    return current;
}

int main(){
    int n;
    while(scanf("%d",&n)==1 && n!=0) {
        long long int helado[n];
        long long int end=0,val;
        for(int i=0; i<n;i++) {
            scanf("%lld",&val);
            end+=val;
            helado[i]=val;
        }
        long long int res =0x3f3f3f3f;
        long long int leftValue = helado[0];
        long long int rightValue = helado[n - 1];
        long long int middle = end - leftValue - rightValue;
        res = min(res, getOF(leftValue, rightValue, middle));
        long long int acuLeft = 1;
        long long int acuRight = n-2;
        while (acuLeft < acuRight) {
            int newLeft = leftValue + helado[acuLeft];
            int newRight = rightValue + helado[acuRight];
            res = min(res, getOF(leftValue, middle - helado[acuRight], newRight));
            res = min(res, getOF(newLeft, middle - helado[acuLeft], rightValue));
            if (newLeft < newRight) {
                leftValue = newLeft;
                middle -= helado[acuLeft++];
            }
            else {
                rightValue = newRight;
                middle -= helado[acuRight--];
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
