#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i <int(b); i++)
using namespace std;

void manacher(int n, string str, int *r) {
    r[0] = 0;
    int p = 0;
    FOR(i, 1, 2*n-1) {
        r[i] = (p/2 + r[p] >= (i+1)/2) ? min(r[2*p - i], p/2 + r[p] - i/2) : 0;
        while (i/2 + r[i] + 1 < n && (i+1)/2 - r[i] - 1 >= 0
        && str[i/2 + r[i] + 1] == str[(i+1)/2 - r[i] - 1]) r[i]++;
        if (i/2 + r[i] > p/2 + r[p]) p = i;
    }
    FOR(i,0,2*n-1) r[i] = r[i]*2 + !(i&1); // change radius to diameter
}

int main()
{
    string line;
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        cin>>line;
        int arr[line.length()*2-1]; memset(arr,0,sizeof(arr));
        int len = line.length();
        manacher(len,line,arr);

        bool flag = false;
        int totalLength = 2*line.length()-1;
        FOR(i,0,(totalLength-1)/2)
        {
            int leng = i*2+1;
            int other = (totalLength-leng)/2 + leng;
            if (arr[i]+arr[other]==line.length()){
                flag = true;
                break;
            }
        }
        if(flag) printf("alindrome\n");
        else if(arr[len-1]==len) printf("palindrome\n");
        else printf("simple\n");
    }
    return 0;
}
