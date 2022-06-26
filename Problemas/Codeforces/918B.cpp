#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
struct IP{
  string name;
  string ip;
};
int main() {
    //freopen("C:/Users/Isaac/Desktop/in.txt","r",stdin);
    //freopen("C:/Users/Isaac/Desktop/out.txt","w",stdout);
    int n,m;
    vector<IP> name;
    string aux,action;
    IP a;
    cin>>n>>m;
    for(int i=0; i<n;i++) {cin>>aux; a.name=aux; cin>>aux;aux+=';'; a.ip=aux;  name.push_back(a);}
    for(int i=0; i<m;i++) {
        cin>>action>>aux;
        for(int j=0; j<n;j++)
        {
            if(name[j].ip==aux)
            {
                cout<<action<<" "<<name[j].ip<<" #"<<name[j].name<<endl;
                break;
            }
        }
    }
    return 0;
}
