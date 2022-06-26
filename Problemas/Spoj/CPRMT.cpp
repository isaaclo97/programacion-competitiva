#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int a_count[27];
    int b_count[27];
    string a, b;
    while(cin>>a>>b)
    {
        memset(a_count,0,sizeof(a_count));
        memset(b_count,0,sizeof(a_count));
        for(unsigned int i=0; i<a.length();i++) a_count[a[i]-'a']++;
        for(unsigned int i=0; i<b.length();i++) b_count[b[i]-'a']++;
        for(int i=0; i<26;i++)
            for(int j=0; j<min(a_count[i],b_count[i]);j++)
            {
                cout<<(char)(i+'a');
            }
        cout<<endl;
    }
    return 0;
}
