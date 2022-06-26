#include <bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 while(n--)
 {
     int p;
     cin>>p;
     map<string,int> a;
                       cin.ignore();
     for(int i=0; i<p;i++)
     {
         string m;
         getline(cin,m);
         if(a.insert(pair<string,int>(m,1)).second == false)
         {
              int k = a.find(m)->second;
              k++;
              map<string, int>::iterator it = a.find(m);
              if (it != a.end())
                  it->second = k;
         }
     }
     cout<<endl;
      map<string,int>::iterator it = a.begin();
     for (it=a.begin(); it!=a.end(); ++it)
        std::cout << it->first << it->second << '\n';
 
 }
    return 0;
} 
