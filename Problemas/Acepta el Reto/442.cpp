#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        bool mayus=true;
    if(b=="snake_case"){
        for(unsigned int i=0; i<a.length();i++)
        {
            if(a[i]=='-')
                cout<<'_';
            else if(i==0)
                cout<<(char)tolower(a[i]);
            else if(a[i]>='A'&&a[i]<='Z')
            {
                cout<<'_'<<(char)tolower(a[i]);
            }
            else
                cout<<(char)a[i];
        }
    }
    else if(b=="kebab-case"){
        for(unsigned int i=0; i<a.length();i++)
        {
            if(a[i]=='_')
                cout<<'-';
            else if(i==0)
                cout<<(char)tolower(a[i]);
            else if(a[i]>='A'&&a[i]<='Z')
            {
                cout<<'-'<<(char)tolower(a[i]);
            }
            else
                cout<<(char)a[i];
        }
    }
    else{
        for(unsigned int i=0; i<a.length();i++)
        {
            if(a[i]=='-'||a[i]=='_')
                mayus=true;
            else if(mayus)
            {
                cout<<(char)toupper(a[i]);
                mayus=false;
            }
            else
                cout<<(char)a[i];
        }
    }
    cout<<endl;
    }
    return 0;
}
