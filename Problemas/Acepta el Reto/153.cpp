#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int hr, min;
        char temp;
        cin>>hr>>temp>>min;
        min = (60 - min) % 60;
        hr = 12 - hr;
        if (min != 0)
            hr--;
        hr = (hr + 12) % 12;
        if (hr == 0)
            hr = 12;
        printf("%02d:%02d\n", hr, min);
    }
}
