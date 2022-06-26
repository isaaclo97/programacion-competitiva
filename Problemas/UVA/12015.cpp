#include <bits/stdc++.h>
using namespace std;
struct Web{
    string url;
    int rel;
};
int main()
{
        int T,count=1;
        cin >> T;
        while(T--)
        {
            Web pages[100];
            int mxRel = -1;
            for(int i = 0; i < 10; i++){
                cin >> pages[i].url >> pages[i].rel;
                if(pages[i].rel > mxRel)mxRel = pages[i].rel;
            }
            cout << "Case #"<< count++ << ":" << endl;
            for(int i = 0; i < 10; i++)if(pages[i].rel == mxRel)cout << pages[i].url << endl;
        }
        return 0;
}
