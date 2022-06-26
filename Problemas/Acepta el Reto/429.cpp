#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases,angares;
    cin>>cases;
    while(cases!=0)
    {
        priority_queue<int> pq;
        for(int i=0; i<cases;i++)
        {
            int a;
            cin>>a;
            pq.push(a);
        }
    cin>>angares;
    int arr2[angares];
    for(int i=0; i<angares;i++)
        cin>>arr2[i];
    bool puede = true;
    for(int i=0; i<angares;i++)
    {
        int a = pq.top();
        pq.pop();
        a-=arr2[i];
        if(a<0)
        {
            puede=false;
            break;
        }
        pq.push(a);
    }
    if(puede)
    cout<<"SI\n";
    else
        cout<<"NO\n";
       cin>>cases;
    }
return 0;
}
