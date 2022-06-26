#include<bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

struct vec{
    int pos;
    vector<int> arr;
};
bool compare(vec A,vec B)
{
    for(unsigned int i=0; i<A.arr.size();i++)
        if(A.arr[i]!=B.arr[i])
          return A.arr[i]<B.arr[i];
    return A.arr[0]<B.arr[0];
}
int main()
{
    int cases; cin>>cases;
    while(cases--)
    {
        int n; cin>>n;
        vector<vec> V;
        vector<string> aux;
        string aux2;
        int m = 0;
        for(int i=1; i<=n;i++)
        {
            cin>>aux2;
            vec a;
            string actual;
            aux.push_back(aux2);
            for(unsigned int j=0; j<aux2.length();j++)
            {
                if(aux2[j]=='.') {a.arr.push_back(stoi(actual)); actual="";}
                else { actual+=aux2[j];}
            }
            a.arr.push_back(stoi(actual));
            a.pos=i;
            int l = a.arr.size();
            m = max(m,l);
            V.push_back(a);
        }
        for(unsigned int i=0; i<V.size();i++)
        {
            vec a = V[i];
            for(int i=a.arr.size(); i<m; i++)
                a.arr.push_back(0);
            V[i]=a;
        }
        sort(V.begin(),V.end(),compare);
        for(int i=0; i<n;i++)
        {
            vec a =V[i];
            if(i==0) cout<<aux[a.pos-1];
            else cout<<" "<<aux[a.pos-1];
        }
        cout<<endl;
    }
    return 0;
}
