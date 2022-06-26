#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,flag=0;
        while(scanf("%d",&n)==1){
            if(flag==1) cout<<endl;
            flag=1;
            int cant,friends;
            string s1,s2;
            vector<string> v;
            map<string, int> M;
            for(int i=0;i<n;i++){
                cin>>s1;
                v.push_back(s1);
            }
            for(int i=0;i<n;i++){
                cin>>s1>>cant>>friends;
                if(friends!=0) M[s1]-=friends*(cant/friends);
                for(int j=0;j<friends;j++){
                    cin>>s2;
                    M[s2]+=cant/friends;
                }
            }
            for(int i=0;i<n;i++)
                cout<<v[i]<<" "<<M[v[i]]<<endl;
        }
        return 0;
}
