#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int i,l,contador=0;
    cin>>i;
    bool q[20002];
    for(int k=0;k<20002;k++)
        q[k]=false;
 
    while(i--)
    {
        cin>>l;
        q[l]=true;
        if(q[l+1]&&q[l-1])
        {
            contador--;
            cout<<contador<<endl;
        }
        else if(q[l+1]||q[l-1])
        {
            cout<<contador<<endl;
        }
        else
        {
            contador++;
            cout<<contador<<endl;
        }
    }
    cout<<"Justice\n";
    return 0;
}
 
