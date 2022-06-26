#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
        int n;
        while (scanf("%d",&n)==1 && n != 0)
        {
            if(n==1||n==9||n==45||n==55||n==99||n==297||n==703||n==999||n==2223||n==2728||n==4879||n==4950||n==5050||n==5292||n==7272||n==7777||n==9999||n==17344||n==22222||n==38962)
                printf("SI\n");
            else printf("NO\n");
        }

        return 0;
}
