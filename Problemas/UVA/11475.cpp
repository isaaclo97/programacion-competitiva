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
    while(getline(cin,line))
    {
        if(line==".") break;
        int arr[line.length()*2-1]; memset(arr,0,sizeof(arr));
        manacher(line.length(),line,arr);
        int sol = line.length()-1; //In worst case last n-1 characters to get the palindromic
        FOR(i,0,2*line.length()-2)
                if(i+arr[i]-1==2*line.length()-2){ sol=min(sol,(i-(arr[i]-1))/2); }
        //(Position - movement to left - 1)/2 position to start
        cout<<line;
        for(int i=sol-1;i>=0;i--)
                    printf("%c",line[i]);
        printf("\n");
    }
    return 0;
}
