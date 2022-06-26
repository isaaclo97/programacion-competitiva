#include <bits/stdc++.h>
using namespace std;

int main()
{
    int height, length,wantedSize[10010];
        while (scanf("%d", &height) && height!=0)
        {
            cin>>length;
            int count=0;
            cin>>wantedSize[0];
            count += height - wantedSize[0];
            for (int i = 1; i < length; ++i)
            {
                cin>>wantedSize[i];
                if (wantedSize[i] != height)
                {
                    int temp = wantedSize[i - 1] - wantedSize[i];
                    if (temp > 0) count += temp;
                }
            }
            cout<<count<<endl;
        }
    return 0;
}
