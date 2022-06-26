#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b > 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int solution(int N,int M)
{
    return N/gcd(N, M);
}
int main()
{
    int M = 20;
    for(int i=1; i<M;i++)
        for(int j=1; j<M;j++)
         printf("%d\n",solution(i,j));
    return 0;
}
